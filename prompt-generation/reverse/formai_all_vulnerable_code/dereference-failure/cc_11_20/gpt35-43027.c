//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure of the database
typedef struct {
    int id;
    char name[50];
    int age;
    char city[50];
} Database;

//Main function
int main() {

    int choice, count = 0, i, id, flag = 0;
    Database *db;
    db = (Database*) malloc(100 * sizeof(Database)); //Allocating memory for database

    printf("Welcome to the Visionary C Database simulation program!\n");

    //Infinite loop until user chooses to exit
    while(1) {

        //Displaying options for user to choose
        printf("\nMENU:\n");
        printf("1. Add a record\n");
        printf("2. Search a record\n");
        printf("3. Display all records\n");
        printf("4. Modify a record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: //For adding a new record

                printf("\nEnter the following details:\n");

                printf("ID: ");
                scanf("%d", &db[count].id);

                printf("Name: ");
                getchar(); //Consuming previous '\n' character
                fgets(db[count].name, 50, stdin);
                db[count].name[strcspn(db[count].name, "\n")] = '\0'; //Replacing '\n' character with '\0'

                printf("Age: ");
                scanf("%d", &db[count].age);

                printf("City: ");
                getchar(); //Consuming previous '\n' character
                fgets(db[count].city, 50, stdin);
                db[count].city[strcspn(db[count].city, "\n")] = '\0'; //Replacing '\n' character with '\0'

                printf("\nRecord added successfully!");
                count++; //Incrementing the count of number of records
                break;

            case 2: //For searching a record

                printf("\nEnter the ID of the record to be searched: ");
                scanf("%d", &id);

                for(i=0; i<count; i++) {
                    if(db[i].id == id) {
                        printf("\nRecord found!\n");
                        printf("ID: %d\nName: %s\nAge: %d\nCity: %s", db[i].id, db[i].name, db[i].age, db[i].city);
                        flag = 1; //Setting flag as 1 to indicate record found
                        break;
                    }
                }

                if(flag == 0) { //If flag is still 0, indicating record not found
                    printf("\nRecord not found!");
                }
                break;

            case 3: //For displaying all records

                printf("\nAll records:\n");

                for(i=0; i<count; i++) {
                    printf("\nID: %d\nName: %s\nAge: %d\nCity: %s\n", db[i].id, db[i].name, db[i].age, db[i].city);
                }
                break;

            case 4: //For modifying a record

                printf("\nEnter the ID of the record to be modified: ");
                scanf("%d", &id);

                for(i=0; i<count; i++) {
                    if(db[i].id == id) {
                        printf("\nEnter the modified details:\n");

                        printf("New name: ");
                        getchar(); //Consuming previous '\n' character
                        fgets(db[i].name, 50, stdin);
                        db[i].name[strcspn(db[i].name, "\n")] = '\0'; //Replacing '\n' character with '\0'

                        printf("New age: ");
                        scanf("%d", &db[i].age);

                        printf("New city: ");
                        getchar(); //Consuming previous '\n' character
                        fgets(db[i].city, 50, stdin);
                        db[i].city[strcspn(db[i].city, "\n")] = '\0'; //Replacing '\n' character with '\0'

                        printf("\nRecord modified successfully!");
                        flag = 1; //Setting flag as 1 to indicate record modified
                        break;
                    }
                }

                if(flag == 0) { //If flag is still 0, indicating record not found
                    printf("\nRecord not found!");
                }
                break;

            case 5: //For deleting a record

                printf("\nEnter the ID of the record to be deleted: ");
                scanf("%d", &id);

                for(i=0; i<count; i++) {
                    if(db[i].id == id) {
                        //Moving all subsequent records one position to the left
                        for(int j=i; j<count-1; j++) {
                            db[j].id = db[j+1].id;
                            strcpy(db[j].name, db[j+1].name);
                            db[j].age = db[j+1].age;
                            strcpy(db[j].city, db[j+1].city);
                        }

                        printf("\nRecord deleted successfully!");
                        count--; //Decrementing the count of number of records
                        flag = 1; //Setting flag as 1 to indicate record deleted
                        break;
                    }
                }

                if(flag == 0) { //If flag is still 0, indicating record not found
                    printf("\nRecord not found!");
                }
                break;

            case 6: //For exiting the program
                printf("\nThank you for using Visionary C Database simulation program!");
                free(db); //Freeing the memory allocated for database
                exit(0);

            default: //For invalid choice entered by user
                printf("\nInvalid choice! Please choose a valid option.");
        }
    }

    return 0;
}