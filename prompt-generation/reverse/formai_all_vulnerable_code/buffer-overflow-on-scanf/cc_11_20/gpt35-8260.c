//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct knight {
    int id;
    char name[50];
    int age;
    char weapon[20];
};

int main() {
    FILE *file;
    file = fopen("knights.dat", "rb");
    
    if (file == NULL) {
        printf("Could not open file.");
        return 1;
    }
    
    int option = 0;
    
    while(option != 5) {
        printf("\n1. List all knights\n");
        printf("2. Search for a knight by name\n");
        printf("3. Add a new knight\n");
        printf("4. Delete a knight by ID\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                struct knight k;
                printf("\nAll knights:\n");
                printf("ID\tName\tAge\tWeapon\n");
                while(fread(&k, sizeof(k), 1, file)) {
                    printf("%d\t%s\t%d\t%s\n", k.id, k.name, k.age, k.weapon);
                }
                rewind(file);
                break;
            }
            case 2: {
                char searchName[50];
                printf("\nEnter the name of the knight you are looking for: ");
                scanf("%s", searchName);
                
                struct knight k;
                int found = 0;
                while(fread(&k, sizeof(k), 1, file)) {
                    if(strcmp(searchName, k.name) == 0) {
                        printf("\nKnight ID: %d\n", k.id);
                        printf("Name: %s\n", k.name);
                        printf("Age: %d\n", k.age);
                        printf("Weapon: %s\n", k.weapon);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("\nKnight not found.\n");
                }
                rewind(file);
                break;
            }
            case 3: {
                struct knight k;
                printf("\nEnter the name of the new knight: ");
                scanf("%s", k.name);
                printf("\nEnter the knight's age: ");
                scanf("%d", &k.age);
                printf("\nEnter the knight's weapon: ");
                scanf("%s", k.weapon);
                
                fseek(file, 0, SEEK_END);
                k.id = ftell(file) / sizeof(k);
                fwrite(&k, sizeof(k), 1, file);
                printf("\nKnight added.\n");

                rewind(file);
                break;
            }
            case 4: {
                int deleteID;
                printf("\nEnter the ID of the knight you want to delete: ");
                scanf("%d", &deleteID);
                
                struct knight k;
                int found = 0;
                long int pos = ftell(file);
                while(fread(&k, sizeof(k), 1, file)) {
                    if(k.id == deleteID) {
                        found = 1;
                        break;
                    }
                    pos = ftell(file);
                }
                
                if(found) {
                    fseek(file, pos, SEEK_SET);
                    fread(&k, sizeof(k), 1, file);
                    fseek(file, pos, SEEK_SET);
                    fwrite(&k, sizeof(k), 1, file);
                    fflush(file);
                    ftruncate(fileno(file), ftell(file));
                    printf("\nKnight deleted.\n");
                } else {
                    printf("\nKnight not found.\n");
                }
                
                rewind(file);
                break;
            }
            case 5:
                printf("\nFarewell, noble user!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                rewind(file);
                break;
        }
    }
    
    fclose(file);
    return 0;
}