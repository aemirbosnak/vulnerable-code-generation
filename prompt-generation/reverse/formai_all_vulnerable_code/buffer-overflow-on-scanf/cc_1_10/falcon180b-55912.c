//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000
#define MAX_BODY_PARTS 20

typedef struct {
    char name[20];
    int age;
    int height;
    int weight;
    int body_parts[MAX_BODY_PARTS];
    int num_body_parts;
} FitnessTracker;

void create_user(FitnessTracker* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height in cm: ");
    scanf("%d", &user->height);
    printf("Enter your weight in kg: ");
    scanf("%d", &user->weight);
    printf("Enter number of body parts you want to track: ");
    scanf("%d", &user->num_body_parts);
    printf("Enter the body parts you want to track (comma separated): ");
    fgets(user->body_parts, MAX_BODY_PARTS, stdin);
    user->body_parts[user->num_body_parts] = '\0';
}

void display_user(FitnessTracker* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %d cm\n", user->height);
    printf("Weight: %d kg\n", user->weight);
    printf("Body parts being tracked: ");
    for(int i=0; i<user->num_body_parts; i++) {
        printf("%s ", user->body_parts[i]);
    }
    printf("\n");
}

int main() {
    FitnessTracker user;
    create_user(&user);
    display_user(&user);
    return 0;
}