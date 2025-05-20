//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    char name[50];
    char email[50];
};

typedef struct record Record;

int main() {

    int choice, id, count = 0, i;
    char name[50], email[50];
    Record *db = NULL;

    while(1) {
        printf("\n");
        printf("==========================\n");
        printf("Welcome to Database Sim!\n");
        printf("==========================\n");
        printf("1. Add record\n");
        printf("2. Retrieve record\n");
        printf("3. Update record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);

                if(count == 0) {
                    db = (Record *) malloc(sizeof(Record));
                } else {
                    db = (Record *) realloc(db, (count + 1) * sizeof(Record));
                }

                db[count].id = id;
                strcpy(db[count].name, name);
                strcpy(db[count].email, email);

                count++;
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);

                for(i = 0; i < count; i++) {
                    if(db[i].id == id) {
                        printf("Record found!\n");
                        printf("ID: %d\n", db[i].id);
                        printf("Name: %s\n", db[i].name);
                        printf("Email: %s\n", db[i].email);
                        break;
                    }
                }

                if(i == count) {
                    printf("Record not found!\n");
                }
                break;

            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);

                for(i = 0; i < count; i++) {
                    if(db[i].id == id) {
                        printf("Enter name: ");
                        scanf("%s", name);
                        printf("Enter email: ");
                        scanf("%s", email);

                        strcpy(db[i].name, name);
                        strcpy(db[i].email, email);

                        printf("Record updated!\n");
                        break;
                    }
                }

                if(i == count) {
                    printf("Record not found!\n");
                }
                break;

            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);

                for(i = 0; i < count; i++) {
                    if(db[i].id == id) {
                        for(int j = i; j < count - 1; j++) {
                            db[j] = db[j+1];
                        }

                        count--;
                        db = (Record *) realloc(db, count * sizeof(Record));

                        printf("Record deleted!\n");
                        break;
                    }
                }

                if(i == count) {
                    printf("Record not found!\n");
                }
                break;

            case 5:
                free(db); // free memory before exiting
                printf("Thank you for using Database Sim! Goodbye :)\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}