//FormAI DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Medieval style database simulation program

typedef struct {
    char name[20];
    int age;
    char job[20];
    int salary;
    char weapon[20];
} Person;

Person *database[50]; //initialize global database with a capacity for 50 people
int num_people = 0; //initialize number of people in database to 0

void add_person() {
    Person *new_person = (Person *) malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%s", new_person->name);
    printf("Enter age: ");
    scanf("%d", &new_person->age);
    printf("Enter job: ");
    scanf("%s", new_person->job);
    printf("Enter salary: ");
    scanf("%d", &new_person->salary);
    printf("Enter weapon: ");
    scanf("%s", new_person->weapon);
    database[num_people++] = new_person;
    printf("Person added!\n");
}

void list_people() {
    printf("%-20s %-10s %-20s %-10s %-20s\n", "Name", "Age", "Job", "Salary", "Weapon");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<num_people; i++) {
        printf("%-20s %-10d %-20s %-10d %-20s\n", database[i]->name, database[i]->age, database[i]->job, database[i]->salary, database[i]->weapon);
    }
}

void search_people() {
    char search_name[20];
    int found = 0;
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    for(int i=0; i<num_people; i++) {
        if(strcmp(database[i]->name, search_name) == 0) {
            found = 1;
            printf("%-20s %-10d %-20s %-10d %-20s\n", database[i]->name, database[i]->age, database[i]->job, database[i]->salary, database[i]->weapon);
            break;
        }
    }
    if(!found) {
        printf("Person not found in database.\n");
    }
}

void delete_person() {
    char delete_name[20];
    int found = 0;
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    for(int i=0; i<num_people; i++) {
        if(strcmp(database[i]->name, delete_name) == 0) {
            found = 1;
            free(database[i]);
            printf("Person deleted from database.\n");
            for(int j=i; j<num_people-1; j++) {
                //shift elements in the array to fill the deleted index
                database[j] = database[j+1];
            }
            num_people--;
            break;
        }
    }
    if(!found) {
        printf("Person not found in database.\n");
    }
}

int main() {
    int choice = 0;
    printf("You have entered the medieval database simulation program.\n");
    while(choice != 5) {
        printf("\n1. Add person to database\n");
        printf("2. List all people in database\n");
        printf("3. Search for person in database\n");
        printf("4. Delete person from database\n");
        printf("5. Exit program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_person();
                break;
            case 2:
                list_people();
                break;
            case 3:
                search_people();
                break;
            case 4:
                delete_person();
                break;
            case 5:
                printf("Exiting program. Thank you for using the medieval database simulation program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}