//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a survivor in the post-apocalyptic world
typedef struct {
    char name[50];
    int age;
    char skills[100];
} Survivor;

// Function to create a survivor
void createSurvivor(FILE *file) {
    Survivor survivor;
    
    printf("Enter survivor name: ");
    scanf("%s", survivor.name);
    printf("Enter survivor age: ");
    scanf("%d", &survivor.age);
    printf("Enter survivor skills: ");
    getchar();  // Clearing the buffer
    fgets(survivor.skills, sizeof(survivor.skills), stdin);
    
    fwrite(&survivor, sizeof(Survivor), 1, file);
    printf("Survivor %s added to the records.\n", survivor.name);
}

// Function to list all survivors
void listSurvivors(FILE *file) {
    Survivor survivor;
    
    fseek(file, 0, SEEK_SET);  // Go to the beginning of the file
    printf("\n--- List of Survivors ---\n");
    while (fread(&survivor, sizeof(Survivor), 1, file) > 0) {
        printf("Name: %s, Age: %d, Skills: %s", survivor.name, survivor.age, survivor.skills);
    }
}

// Function to search for a survivor
void searchSurvivor(FILE *file) {
    char nameToSearch[50];
    Survivor survivor;
    int found = 0;

    printf("Enter the name of the survivor to search: ");
    scanf("%s", nameToSearch);
    
    fseek(file, 0, SEEK_SET);
    while (fread(&survivor, sizeof(Survivor), 1, file) > 0) {
        if (strcmp(survivor.name, nameToSearch) == 0) {
            printf("Survivor Found - Name: %s, Age: %d, Skills: %s", survivor.name, survivor.age, survivor.skills);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Survivor not found.\n");
    }
}

// Function to delete a survivor (recreate file without the deleted one)
void deleteSurvivor(FILE *file) {
    char nameToDelete[50];
    Survivor survivor;
    FILE *tempFile = fopen("temp.bin", "wb");
    
    if (!tempFile) {
        printf("Error creating temp file.\n");
        return;
    }

    printf("Enter the name of the survivor to delete: ");
    scanf("%s", nameToDelete);
    
    fseek(file, 0, SEEK_SET);
    int deleted = 0;
    while (fread(&survivor, sizeof(Survivor), 1, file) > 0) {
        if (strcmp(survivor.name, nameToDelete) != 0) {
            fwrite(&survivor, sizeof(Survivor), 1, tempFile);
        } else {
            deleted = 1;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("survivors.bin");
    rename("temp.bin", "survivors.bin");
    
    if (deleted) {
        printf("Survivor %s deleted from records.\n", nameToDelete);
    } else {
        printf("Survivor not found for deletion.\n");
    }
}

// Main function where the apocalypse begins
int main() {
    FILE *file = fopen("survivors.bin", "ab+");
    if (!file) {
        printf("Error opening the survivors data file.\n");
        return 1;
    }

    int choice;

    do {
        printf("\n--- Survivor Management System ---\n");
        printf("1. Create Survivor\n");
        printf("2. List Survivors\n");
        printf("3. Search Survivor\n");
        printf("4. Delete Survivor\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createSurvivor(file);
                break;
            case 2:
                listSurvivors(file);
                break;
            case 3:
                searchSurvivor(file);
                break;
            case 4:
                deleteSurvivor(file);
                file = fopen("survivors.bin", "ab+"); // Reopen the original file
                break;
            case 5:
                printf("Exiting the survivor management system...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}