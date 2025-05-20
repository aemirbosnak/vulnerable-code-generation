//FormAI DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our index
typedef struct {
    char keyword[20];
    int position;
} Index;

// Define a struct for our database
typedef struct {
    char name[50];
    int age;
    char address[100];
    char favorite_food[50];
} Person;

// Define a function to create our index based on a keyword and position
Index* create_index(char keyword[], int position){
    Index* idx = (Index*)malloc(sizeof(Index));
    strcpy(idx->keyword, keyword);
    idx->position = position;
    return idx;
}

// Define a function to display our database records
void display_database(Person* people[], int num_people){
    printf("\n===================\n");
    printf("| %-15s| %-5s| %-30s| %-20s|\n", "Name", "Age", "Address", "Favorite Food");
    printf("===================\n");

    for(int i=0; i<num_people; i++){
        printf("| %-15s| %-5d| %-30s| %-20s|\n", people[i]->name, people[i]->age, people[i]->address, people[i]->favorite_food);
    }

    printf("===================\n");
}

// Define our main function
int main(){
    // Initialize an array of Person pointers to store database records
    Person* people[1000];
    int num_people = 0;

    // Initialize an array of Index pointers to store our index
    Index* index[1000];
    int num_index = 0;

    // Open our database file
    FILE* fp = fopen("database.txt", "r");

    // Check if the file opened successfully
    if(fp == NULL){
        printf("Error: Could not open file.\n");
        return 0;
    }

    // Read in each line of the file and create a new Person struct for each record
    char line[200];
    while(fgets(line, sizeof(line), fp)){
        Person* p = (Person*)malloc(sizeof(Person));
        sscanf(line, "%[^,],%d,%[^,],%s", p->name, &p->age, p->address, p->favorite_food);
        people[num_people++] = p;

        // Split the address string into individual words and create a new index for each word
        char* token = strtok(p->address, " ");
        while(token != NULL){
            index[num_index++] = create_index(token, num_people-1); // We subtract 1 from num_people because it was incremented after adding the last person to the array
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(fp);

    // Display the database records
    display_database(people, num_people);

    // Prompt the user to search for a record based on a keyword
    char keyword[20];
    printf("\nEnter a keyword to search the database: ");
    scanf("%s", keyword);

    // Search the index array for all records containing the keyword in their address
    int num_results = 0;
    int results[1000];
    for(int i=0; i<num_index; i++){
        if(strcmp(index[i]->keyword, keyword) == 0){
            results[num_results++] = index[i]->position;
        }
    }

    // Display the search results
    printf("\nSearch results:\n");
    if(num_results == 0){
        printf("No results found.\n");
    } else {
        printf("| %-15s| %-5s| %-30s| %-20s|\n", "Name", "Age", "Address", "Favorite Food");
        printf("===================\n");
        for(int i=0; i<num_results; i++){
            Person* p = people[results[i]];
            printf("| %-15s| %-5d| %-30s| %-20s|\n", p->name, p->age, p->address, p->favorite_food);
        }
        printf("===================\n");
    }

    // Free allocated memory
    for(int i=0; i<num_people; i++){
        free(people[i]);
    }
    for(int i=0; i<num_index; i++){
        free(index[i]);
    }

    return 0;
}