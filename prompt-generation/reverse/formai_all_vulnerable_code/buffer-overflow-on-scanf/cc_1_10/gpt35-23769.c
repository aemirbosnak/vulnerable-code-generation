//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    char occupation[20];
    int age;
} Person;

int main() {
    FILE *datafile;
    char filename[20] = "people.db";
    datafile = fopen(filename, "wb");
    Person people[5] = {
        {1, "John", "Blacksmith", 35},
        {2, "Mary", "Baker", 27},
        {3, "Robert", "Soldier", 40},
        {4, "Elizabeth", "Weaver", 18},
        {5, "Henry", "Farmer", 50}
    };
    fwrite(&people, sizeof(Person), 5, datafile);
    fclose(datafile);
    printf("Data has been written to %s\n", filename);

    int option;
    printf("Select an option:\n");
    printf("1 - Search for person by id\n");
    printf("2 - Search for people by occupation\n");
    scanf("%d", &option);

    switch(option) {
        case 1: {
            int id;
            printf("Enter the id of the person you are looking for:\n");
            scanf("%d", &id);
            datafile = fopen(filename, "rb");
            if (datafile != NULL) {
                Person person;
                while(fread(&person, sizeof(Person), 1, datafile)) {
                    if (person.id == id) {
                        printf("id: %d\nname: %s\noccupation: %s\nage: %d\n", 
                               person.id, person.name, person.occupation, person.age);
                        break;
                    }
                }
                fclose(datafile);
            } else {
                printf("Error: unable to open file\n");
            }
            break;
        }

        case 2: {
            char occupation[20];
            printf("Enter the occupation of the people you are looking for:\n");
            scanf("%s", occupation);
            datafile = fopen(filename, "rb");
            if (datafile != NULL) {
                Person person;
                while(fread(&person, sizeof(Person), 1, datafile)) {
                    if (strcmp(person.occupation, occupation) == 0) {
                        printf("id: %d\nname: %s\noccupation: %s\nage: %d\n", 
                               person.id, person.name, person.occupation, person.age);
                    }
                }
                fclose(datafile);
            } else {
                printf("Error: unable to open file\n");
            }
            break;
        }

        default: {
            printf("Invalid option selected. Please select 1 or 2.\n");
        }
    }

    return 0;
}