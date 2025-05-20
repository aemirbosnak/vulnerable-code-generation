//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    char email[50];
};

int main() {
    struct Record database[MAX_RECORDS];
    int num_records = 0;
    bool running = true;

    while(running) {
        printf("Please enter a command (add, delete, search, print, quit):\n");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            if(num_records == MAX_RECORDS) {
                printf("Error: database is full\n");
            } else {
                printf("Please enter the ID of the record:\n");
                int id;
                scanf("%d", &id);

                bool already_exists = false;
                for(int i = 0; i < num_records; i++) {
                    if(database[i].id == id) {
                        already_exists = true;
                        break;
                    }
                }

                if(already_exists) {
                    printf("Error: record with ID %d already exists\n", id);
                } else {
                    struct Record new_record;
                    new_record.id = id;

                    printf("Please enter the name of the record:\n");
                    scanf("%s", new_record.name);

                    printf("Please enter the email of the record:\n");
                    scanf("%s", new_record.email);

                    database[num_records] = new_record;
                    num_records++;

                    printf("Record added successfully\n");
                }
            }
        } else if(strcmp(command, "delete") == 0) {
            printf("Please enter the ID of the record to delete:\n");
            int id;
            scanf("%d", &id);

            bool found_record = false;
            for(int i = 0; i < num_records; i++) {
                if(database[i].id == id) {
                    found_record = true;
                    num_records--;

                    for(int j = i; j < num_records; j++) {
                        database[j] = database[j+1];
                    }

                    printf("Record with ID %d deleted successfully\n", id);
                    break;
                }
            }

            if(!found_record) {
                printf("Error: record with ID %d not found\n", id);
            }
        } else if(strcmp(command, "search") == 0) {
            printf("Please enter the ID of the record to search:\n");
            int id;
            scanf("%d", &id);

            bool found_record = false;
            for(int i = 0; i < num_records; i++) {
                if(database[i].id == id) {
                    printf("Record found:\n");
                    printf("ID: %d\n", database[i].id);
                    printf("Name: %s\n", database[i].name);
                    printf("Email: %s\n", database[i].email);

                    found_record = true;
                    break;
                }
            }

            if(!found_record) {
                printf("Error: record with ID %d not found\n", id);
            }
        } else if(strcmp(command, "print") == 0) {
            printf("Database contains %d records:\n", num_records);
            for(int i = 0; i < num_records; i++) {
                printf("Record %d:\n", i+1);
                printf("ID: %d\n", database[i].id);
                printf("Name: %s\n", database[i].name);
                printf("Email: %s\n", database[i].email);
            }
        } else if(strcmp(command, "quit") == 0) {
            running = false;
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}