//FormAI DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random number to be used as a fake ID
int generateRandomID() {
    int num = (rand() % (9999 - 1000 + 1)) + 1000;
    return num;
}

int main() {
    // Initializing an array of structs to hold info on fake customers
    struct Customer {
        char name[50];
        int age;
        char city[25];
        int id;
    } customers[5];

    // Hardcoding some sample data to be used for the array
    strcpy(customers[0].name, "John Smith");
    customers[0].age = 30;
    strcpy(customers[0].city, "New York City");
    customers[0].id = generateRandomID();

    strcpy(customers[1].name, "Jane Doe");
    customers[1].age = 25;
    strcpy(customers[1].city, "Los Angeles");
    customers[1].id = generateRandomID();

    strcpy(customers[2].name, "Bob Ross");
    customers[2].age = 50;
    strcpy(customers[2].city, "Seattle");
    customers[2].id = generateRandomID();

    strcpy(customers[3].name, "Elon Musk");
    customers[3].age = 45;
    strcpy(customers[3].city, "Austin");
    customers[3].id = generateRandomID();

    strcpy(customers[4].name, "Kanye West");
    customers[4].age = 40;
    strcpy(customers[4].city, "Chicago");
    customers[4].id = generateRandomID();

    // Print out all customers' info
    printf("Here are all of our customers:\n");
    for(int i = 0; i < 5; i++) {
        printf("Name: %s\n", customers[i].name);
        printf("Age: %d\n", customers[i].age);
        printf("City: %s\n", customers[i].city);
        printf("ID: %d\n\n", customers[i].id);
    }

    // Ask user for the ID they want to look up
    int searchID;
    printf("Enter the ID of the customer you want to find: ");
    scanf("%d", &searchID);

    // Search for the customer with the ID that the user inputted
    for(int i = 0; i < 5; i++) {
        if(searchID == customers[i].id) {
            printf("Name: %s\n", customers[i].name);
            printf("Age: %d\n", customers[i].age);
            printf("City: %s\n", customers[i].city);
            printf("ID: %d\n", customers[i].id);
            return 0;
        }
    }

    // If no match is found, deliver a funny message
    printf("Sorry, we couldn't find that ID. Maybe they haven't signed up for our database yet, or maybe they're a spy. Either way, try searching for someone else!\n");

    return 0;
}