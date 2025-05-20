//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 256
#define MAX_AGE 100

// Struct to store user information
struct user {
    char name[MAX_NAME_LEN];
    int age;
};

// Function to read a user's information from a file
struct user read_user_info(const char* filename) {
    struct user user;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return user;
    }
    fscanf(file, "%s %d", user.name, &user.age);
    fclose(file);
    return user;
}

// Function to write a user's information to a file
void write_user_info(const char* filename, struct user user) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s %d\n", user.name, user.age);
    fclose(file);
}

int main() {
    struct user user;
    // Read user information from a file
    user = read_user_info("user_info.txt");
    if (user.age < 18) {
        printf("You are a minor, please do not proceed.");
        return 0;
    }
    // Calculate the user's remaining lifespan
    int remaining_life = 80 - user.age;
    // Print the user's information and remaining lifespan
    printf("Hello, %s! You have lived for %d years so far, and have %d years remaining.\n",
           user.name, user.age, remaining_life);
    // Write the user's information and remaining lifespan to a file
    write_user_info("user_info_updated.txt", user);
    return 0;
}