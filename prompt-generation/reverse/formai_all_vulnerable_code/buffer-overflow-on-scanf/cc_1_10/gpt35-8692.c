//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

// function to write data to file
void writeToFile(char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Error opening file.");
        return;
    }
    char name[50];
    int age;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    fprintf(file, "%s %d", name, age);
    printf("Data successfully written to file.\n");
    fclose(file);
}

// function to read data from file
void readFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.");
        return;
    }
    char name[50];
    int age;
    fscanf(file, "%s %d", name, &age);
    printf("Name: %s\nAge: %d\n", name, age);
    fclose(file);
}

int main() {
    int choice;
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);
    while (1) {
        printf("\nEnter your choice:\n1. Write to file\n2. Read from file\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                writeToFile(fileName);
                break;
            case 2:
                readFromFile(fileName);
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter again.\n");
                break;
        }
    }
    return 0;
}