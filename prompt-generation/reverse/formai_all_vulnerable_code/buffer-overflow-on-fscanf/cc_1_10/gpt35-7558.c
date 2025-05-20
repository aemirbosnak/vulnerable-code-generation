//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

void displayRecord(Record record){
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Address: %s\n\n", record.address);
}

int main(){
    int choice = 0;
    int count = 0;
    FILE *file;
    char filename[] = "database.txt";
    Record records[100];

    while(choice != 4){
        printf("1. Add a record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("clear");
                printf("Enter ID, Name, Age, and Address:\n");
                scanf("%d %s %d %s", &records[count].id, records[count].name, &records[count].age, records[count].address);
                count++;
                printf("Record added successfully!\n\n");
                file = fopen(filename, "a");

                if(file == NULL){
                    printf("Error: Could not open file!\n");
                }else{
                    fprintf(file, "%d %s %d %s\n", records[count - 1].id, records[count - 1].name, records[count - 1].age, records[count - 1].address);
                    fclose(file);
                }
                break;

            case 2:
                system("clear");
                printf("Displaying all records:\n\n");
                file = fopen(filename, "r");

                if(file == NULL){
                    printf("Error: Could not open file!\n");
                }else{
                    Record record;
                    while(fscanf(file, "%d %s %d %s", &record.id, record.name, &record.age, record.address) != EOF){
                        displayRecord(record);
                    }
                    fclose(file);
                }
                break;

            case 3:
                system("clear");
                printf("Enter ID to search for: ");
                int searchId;
                scanf("%d", &searchId);
                file = fopen(filename, "r");

                if(file == NULL){
                    printf("Error: Could not open file!\n");
                }else{
                    Record record;
                    int found = 0;
                    while(fscanf(file, "%d %s %d %s", &record.id, record.name, &record.age, record.address) != EOF){
                        if(record.id == searchId){
                            displayRecord(record);
                            found = 1;
                            break;
                        }
                    }
                    if(!found){
                        printf("Record not found!\n\n");
                    }
                    fclose(file);
                }
                break;

            case 4:
                printf("Exiting program...\n\n");
                break;

            default:
                printf("Invalid choice, please try again!\n\n");
        }
    }
    return 0;
}