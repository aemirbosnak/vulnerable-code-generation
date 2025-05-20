//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void generate_rating(char *name);
bool is_valid_name(char *name);
void print_name(char *name);
void print_rating(char *rating);

int main() {
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    if (is_valid_name(name)) {
        generate_rating(name);
    } else {
        printf("Invalid name. Please enter a valid name.\n");
    }

    return 0;
}

void generate_rating(char *name) {
    char rating[10];
    sprintf(rating, "R-%s", name);
    printf("Your movie rating is: ");
    print_rating(rating);
}

bool is_valid_name(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return false;
        }
    }
    return true;
}

void print_name(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (isalpha(name[i])) {
            name[i] = toupper(name[i]);
        }
    }
    printf("%s\n", name);
}

void print_rating(char *rating) {
    int i;
    for (i = 0; i < strlen(rating); i++) {
        if (isalpha(rating[i])) {
            rating[i] = toupper(rating[i]);
        }
    }
    printf("%s\n", rating);
}