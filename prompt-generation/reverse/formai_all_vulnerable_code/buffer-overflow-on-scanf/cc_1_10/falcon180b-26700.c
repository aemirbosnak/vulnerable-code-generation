//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    int steps;
    time_t last_updated;
} user;

user create_user() {
    user u;
    printf("Enter your name: ");
    scanf("%s", u.name);
    printf("Enter your age: ");
    scanf("%d", &u.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &u.weight);
    printf("Enter your height (in cm): ");
    scanf("%f", &u.height);
    u.steps = 0;
    u.last_updated = time(NULL);
    return u;
}

void update_user_steps(user* u) {
    printf("Enter the number of steps you took today: ");
    scanf("%d", &u->steps);
    u->last_updated = time(NULL);
}

void print_user_info(user u) {
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Weight: %f kg\n", u.weight);
    printf("Height: %f cm\n", u.height);
    printf("Steps taken: %d\n", u.steps);
    printf("Last updated: %s", ctime(&u.last_updated));
}

int main() {
    user u = create_user();
    while (1) {
        int choice;
        printf("\n1. Update steps\n2. View user info\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                update_user_steps(&u);
                break;
            case 2:
                print_user_info(u);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}