//FormAI DATASET v1.0 Category: Database querying ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program queries a futuristic database of mutant animals and their powers

typedef struct{
    char name[20];
    char power[50];
    int age;
    float weight;
} MutantAnimal;

int main(){
    int option = 0;
    int numQueryItems = 0;
    MutantAnimal *database = NULL; // Dynamic array of mutant animals
    int numMutantAnimals = 0; // Keep track of number of animals in database

    printf("Welcome to the Mutant Animal Database!\n");

    // Allow user to add animals to the database
    while(option != 4){
        printf("\nWhat would you like to do?\n");
        printf("1. Add a mutant animal to the database\n");
        printf("2. View all mutant animals in the database\n");
        printf("3. Query the database\n");
        printf("4. Quit\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nAdding a mutant animal to the database.\n");

                MutantAnimal newAnimal;

                printf("Enter the animal's name: ");
                scanf("%s", newAnimal.name);

                printf("Enter the animal's power: ");
                scanf("%s", newAnimal.power);

                printf("Enter the animal's age: ");
                scanf("%d", &newAnimal.age);

                printf("Enter the animal's weight: ");
                scanf("%f", &newAnimal.weight);

                numMutantAnimals++;

                // Increase the size of the database by 1 and add the new animal
                database = (MutantAnimal*) realloc(database, numMutantAnimals * sizeof(MutantAnimal));
                database[numMutantAnimals-1] = newAnimal;

                printf("Mutant animal added successfully!\n");
                break;
            case 2:
                printf("\nViewing all mutant animals in the database.\n");

                // If no animals have been added yet, let the user know
                if(numMutantAnimals == 0){
                    printf("No mutant animals in database.\n");
                } else {
                    // Loop through all animals and print their information
                    for(int i=0; i<numMutantAnimals; i++){
                        printf("\nName: %s\nPower: %s\nAge: %d\nWeight: %0.2f\n", database[i].name, database[i].power, database[i].age, database[i].weight);
                    }
                }
                break;
            case 3:
                printf("\nQuerying the mutant animal database.\n");

                printf("How many query items would you like to use? ");
                scanf("%d", &numQueryItems);

                // Allocate memory for query items
                char **queryItems = (char**) malloc(numQueryItems * sizeof(char*));
                for(int i=0; i<numQueryItems; i++){
                    queryItems[i] = (char*) malloc(20 * sizeof(char));
                }

                // Get query items from user
                printf("Enter query items:\n");
                for(int i=0; i<numQueryItems; i++){
                    printf("%d. ", i+1);
                    scanf("%s", queryItems[i]);
                }

                // Loop through all animals and check if they match the query items
                for(int i=0; i<numMutantAnimals; i++){
                    int matches = 0;
                    for(int j=0; j<numQueryItems; j++){
                        if(strstr(database[i].name, queryItems[j]) != NULL || strstr(database[i].power, queryItems[j]) != NULL){
                            matches++;
                        }
                    }
                    if(matches == numQueryItems){
                        printf("\nName: %s\nPower: %s\nAge: %d\nWeight: %0.2f\n", database[i].name, database[i].power, database[i].age, database[i].weight);
                    }
                }

                // Free memory allocated for query items
                for(int i=0; i<numQueryItems; i++){
                    free(queryItems[i]);
                }
                free(queryItems);

                break;
            case 4:
                printf("\nExiting the Mutant Animal Database.\n");
                break;
            default:
                printf("\nInvalid option selected. Please try again.\n");
                break;
        }
    }

    free(database);

    return 0;
}