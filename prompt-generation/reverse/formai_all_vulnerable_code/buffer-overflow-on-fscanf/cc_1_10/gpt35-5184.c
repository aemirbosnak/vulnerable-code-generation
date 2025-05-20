//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    int id;
    char name[20];
    int age;
}Person;

int main(){
    srand(time(0));
    printf("Welcome to the Database Simulation Game!\n");
    printf("You are now the proud owner of your very own database!\n");
    printf("What would you like to do?\n");
    printf("1. Add a person\n");
    printf("2. Remove a person\n");
    printf("3. Search for a person\n");

    int choice;
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
        {
            printf("Please enter the person's name: ");
            char name[20];
            scanf("%s", name);
            int age = rand()%100;
            int id = rand()%100000;
            printf("Adding %s with ID %d and age %d to database...\n", name, id, age);
            Person new_person = {id, name, age};
            FILE *f = fopen("database.txt", "a+");
            fprintf(f, "%d %s %d\n", new_person.id, new_person.name, new_person.age);
            fclose(f);
            printf("Person added successfully!\n");
            break;
        }

        case 2:
        {
            printf("Please enter the person's ID: ");
            int id;
            scanf("%d", &id);
            FILE *f = fopen("database.txt", "r");
            FILE *temp = fopen("temp.txt", "w");
            Person current_person;
            int found = 0;
            while(fscanf(f, "%d %s %d\n", &current_person.id, current_person.name, &current_person.age)!=EOF){
                if(current_person.id == id){
                    printf("Removing %s with ID %d from database...\n", current_person.name, current_person.id);
                    found = 1;
                }
                else{
                    fprintf(temp, "%d %s %d\n", current_person.id, current_person.name, current_person.age);
                }
            }
            fclose(f);
            fclose(temp);
            remove("database.txt");
            rename("temp.txt", "database.txt");
            if(found){
                printf("Person removed successfully!\n");
            }
            else{
                printf("Person not found in database!\n");
            }
            break;
        }

        case 3:
        {
            printf("Please enter the person's ID: ");
            int id;
            scanf("%d", &id);
            FILE *f = fopen("database.txt", "r");
            Person current_person;
            int found = 0;
            while(fscanf(f, "%d %s %d\n", &current_person.id, current_person.name, &current_person.age)!=EOF){
                if(current_person.id == id){
                    printf("Person found:\n");
                    printf("ID: %d\n", current_person.id);
                    printf("Name: %s\n", current_person.name);
                    printf("Age: %d\n", current_person.age);
                    found = 1;
                }
            }
            fclose(f);
            if(!found){
                printf("Person not found in database!\n");
            }
            break;
        }

        default:
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}