//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_ANSWERS 5

typedef struct {
    char name[50];
    int age;
    char star_sign[20];
    int lucky_number;
} Person;

int main() {
    time_t t = time(NULL);
    srand(t);

    // Create an array of 5 people
    Person people[NUM_OF_ANSWERS] = {
        {"John Doe", 25, "Aries", 3},
        {"Jane Doe", 30, "Taurus", 5},
        {"Mike Smith", 40, "Gemini", 7},
        {"Sarah Jones", 50, "Virgo", 9},
        {"Bill Anderson", 60, "Scorpio", 11}
    };

    // Get the user's name, age, and star sign
    char user_name[50];
    int user_age;
    char user_star_sign[20];

    printf("Please enter your name: ");
    scanf("%s", user_name);

    printf("Please enter your age: ");
    scanf("%d", &user_age);

    printf("Please enter your star sign: ");
    scanf("%s", user_star_sign);

    // Find the user's lucky number
    int user_lucky_number = people[0].lucky_number;

    for (int i = 0; i < NUM_OF_ANSWERS; i++) {
        if (strcmp(people[i].name, user_name) == 0 && people[i].age == user_age && strcmp(people[i].star_sign, user_star_sign) == 0) {
            user_lucky_number = people[i].lucky_number;
        }
    }

    // Print the user's lucky number
    printf("Your lucky number is: %d", user_lucky_number);

    return 0;
}