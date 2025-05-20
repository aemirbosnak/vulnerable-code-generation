//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAX_NO_OF_USERS 100
#define MAX_NO_OF_ITEMS 1000

// Structure to store user information
typedef struct {
    char name[50];
    int age;
    int gender;
    int rating[MAX_NO_OF_ITEMS];
} user_info_t;

// Structure to store item information
typedef struct {
    char name[50];
    int price;
    int rating;
} item_info_t;

// Function to read user ratings from a file
void read_user_ratings(user_info_t *users, int no_of_users, char *file_name) {
    FILE *file = fopen(file_name, "r");
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }

    while (i < no_of_users) {
        fscanf(file, "%s %d %d", users[i].name, &users[i].age, &users[i].gender);
        for (int j = 0; j < MAX_NO_OF_ITEMS; j++) {
            fscanf(file, "%d", &users[i].rating[j]);
        }
        i++;
    }

    fclose(file);
}

// Function to calculate the average rating for an item
float calculate_average_rating(item_info_t *items, int no_of_items, int *ratings) {
    int i = 0;
    int sum = 0;

    for (i = 0; i < no_of_items; i++) {
        sum += ratings[i];
    }

    return (float)sum / no_of_items;
}

// Function to print the top rated items
void print_top_rated_items(item_info_t *items, int no_of_items, int *ratings) {
    int i = 0;
    int j = 0;

    for (i = 0; i < no_of_items; i++) {
        if (ratings[i] > j) {
            j = ratings[i];
            printf("%d. %s - Rating: %d\n", i + 1, items[i].name, j);
        }
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // Create an array of user information
    user_info_t users[MAX_NO_OF_USERS];

    // Create an array of item information
    item_info_t items[MAX_NO_OF_ITEMS];

    // Initialize user ratings
    int no_of_users = 10;
    int ratings[MAX_NO_OF_USERS][MAX_NO_OF_ITEMS] = {{0}};

    // Read user ratings from a file
    read_user_ratings(users, no_of_users, "user_ratings.txt");

    // Generate random ratings for items
    for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
        items[i].rating = (int)(rand() % 5) + 1;
    }

    // Calculate the average rating for each item
    float average_rating[MAX_NO_OF_ITEMS];
    for (int i = 0; i < MAX_NO_OF_ITEMS; i++) {
        average_rating[i] = calculate_average_rating(items, i + 1, ratings[0]);
    }

    // Print the top rated items
    print_top_rated_items(items, MAX_NO_OF_ITEMS, ratings[0]);

    return 0;
}