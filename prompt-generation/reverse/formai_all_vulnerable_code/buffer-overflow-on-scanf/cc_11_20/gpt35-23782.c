//FormAI DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// C struct to represent a survivor
typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char location[100];
} Survivor;

int main() {
    FILE *fp;
    char filename[50] = "survivors.dat";
    int choice, id, num_survivors = 0;
    char name[50], gender[10], location[100];
    int age;

    // Read the number of existing survivors from file
    fp = fopen(filename, "r");
    if(fp) {
        fread(&num_survivors, sizeof(int), 1, fp);
        fclose(fp);
    }

    do {
        printf("\nSurvivor Database\n------------------------\n");
        printf("1. Add Survivor\n");
        printf("2. Remove Survivor\n");
        printf("3. Search Survivor\n");
        printf("4. List All Survivors\n");
        printf("5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Adding a survivor
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter gender: ");
                scanf("%s", gender);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter location: ");
                scanf("%s", location);

                // Generate unique ID for the survivor
                id = time(NULL);

                // Add the survivor details to the file
                fp = fopen(filename, "a+");
                if(fp) {
                    Survivor survivor = {id, name, age, gender, location};
                    fwrite(&survivor, sizeof(Survivor), 1, fp);
                    fclose(fp);
                    num_survivors++;
                    printf("\nSurvivor added successfully with ID %d\n", id);
                } else {
                    printf("\nError: Could not add survivor\n");
                }

                break;

            case 2: // Removing a survivor
                printf("\nEnter the ID of the survivor to remove: ");
                scanf("%d", &id);

                // Find the survivor with the given ID and remove them
                fp = fopen(filename, "rb");
                if(fp) {
                    Survivor survivor;
                    int found = 0;

                    // Create a temporary file to store survivors not being removed
                    FILE *temp = fopen("temp.dat", "wb");

                    // Copy each survivor to the temporary file except the one being removed
                    while(fread(&survivor, sizeof(Survivor), 1, fp)) {
                        if(survivor.id != id) {
                            fwrite(&survivor, sizeof(Survivor), 1, temp);
                        } else {
                            found = 1;
                        }
                    }

                    fclose(fp);
                    fclose(temp);

                    if(found) {
                        // Replace the original file with the temporary file
                        remove(filename);
                        rename("temp.dat", filename);
                        num_survivors--;
                        printf("\nSurvivor with ID %d successfully removed\n", id);
                    } else {
                        printf("\nError: Could not find survivor with ID %d\n", id);
                    }
                } else {
                    printf("\nError: Could not remove survivor\n");
                }

                break;

            case 3: // Searching for a survivor
                printf("\nEnter the ID of the survivor tosearch for: ");
                scanf("%d", &id);

                // Find the survivor with the given ID and display their details
                fp = fopen(filename, "rb");
                if(fp) {
                    Survivor survivor;
                    int found = 0;

                    while(fread(&survivor, sizeof(Survivor), 1, fp)) {
                        if(survivor.id == id) {
                            found = 1;
                            printf("\nSurvivor Found\n");
                            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nLocation: %s\n",
                                    survivor.id, survivor.name, survivor.age, survivor.gender, survivor.location);
                        }
                    }

                    fclose(fp);

                    if(!found) {
                        printf("\nError: Could not find survivor with ID %d\n", id);
                    }
                } else {
                    printf("\nError: Could not search database\n");
                }

                break;

            case 4: // Listing all survivors
                fp = fopen(filename, "rb");
                if(fp) {
                    Survivor survivor;

                    while(fread(&survivor, sizeof(Survivor), 1, fp)) {
                        printf("\nID: %d\nName: %s\nAge: %d\nGender: %s\nLocation: %s\n",
                                survivor.id, survivor.name, survivor.age, survivor.gender, survivor.location);
                    }

                    fclose(fp);
                } else {
                    printf("\nError: Could not list survivors\n");
                }

                break;

            case 5: // Quitting the program
                printf("\nExiting the program...\n");
                break;

            default: // Invalid choice
                printf("\nError: Invalid choice\n");
                break;
        }
    } while(choice != 5);

    // Update the number of survivors in file
    fp = fopen(filename, "wb");
    if(fp) {
        fwrite(&num_survivors, sizeof(int), 1, fp);
        fclose(fp);
    }

    return 0;
}