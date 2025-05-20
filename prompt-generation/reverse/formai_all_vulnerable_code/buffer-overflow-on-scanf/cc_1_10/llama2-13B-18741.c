//LLAMA2-13B DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Generate a random name for the player
    char name[MAX_NAME_LEN];
    srandom(time(NULL));
    for (int i = 0; i < MAX_NAME_LEN; i++) {
        name[i] = 'A' + (rand() % 26);
    }

    // Prompt the player to enter their age
    printf("Hello, %s! Please enter your age: ", name);
    int age;
    scanf("%d", &age);

    // Check if the player's age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Invalid age! Please try again.\n");
        return 1;
    }

    // Print a personalized message based on the player's age
    switch (age) {
        case 1:
            printf("Happy birthday, young one! May your dreams come true!\n");
            break;
        case 10:
            printf("Wow, you're a big kid now! Keep on growing and learning!\n");
            break;
        case 20:
            printf("Congratulations on reaching adulthood! The world is your playground now.\n");
            break;
        case 50:
            printf("Half a century young! Here's to many more years of wisdom and adventure!\n");
            break;
        case 100:
            printf("Wow, you've lived a long and full life! We salute you, elder statesperson!\n");
            break;
        default:
            printf("Age %d is a bit... unusual. But we still appreciate your uniqueness!\n", age);
            break;
    }

    return 0;
}