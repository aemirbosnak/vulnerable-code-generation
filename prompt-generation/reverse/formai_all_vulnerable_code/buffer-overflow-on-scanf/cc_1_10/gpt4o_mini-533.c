//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define NUM_FORTUNES 10
#define MAX_NAME_LENGTH 50

const char *fortunes[NUM_FORTUNES] = {
    "You will find a helpful friend soon.",
    "A thrilling time is in your near future.",
    "Your hard work will pay off in ways you don’t expect.",
    "Don't be afraid to take a chance; fortune favors the bold.",
    "A pleasant surprise is waiting for you.",
    "You will soon receive some good news.",
    "The stars are in your favor; take risks.",
    "Opportunities are all around you; seize them!",
    "You will meet someone who will inspire you.",
    "A long-lost friend will reconnect with you soon."
};

typedef struct {
    char name[MAX_NAME_LENGTH];
} User;

void *get_fortune(void *arg) {
    User *user = (User *)arg;
    int fortune_index = rand() % NUM_FORTUNES;
    printf("%s, your fortune: %s\n", user->name, fortunes[fortune_index]);
    return NULL;
}

void *request_fortune(void *arg) {
    User *user = (User *)arg;
    char choice;

    while (1) {
        printf("%s, do you want to know your fortune? (y/n): ", user->name);
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            pthread_t thread;
            pthread_create(&thread, NULL, get_fortune, user);
            pthread_detach(thread); // Automatically handle the thread after it completes
        } else if (choice == 'n' || choice == 'N') {
            printf("Alright, have a great day, %s!\n", user->name);
            break;
        } else {
            printf("Please enter 'y' for yes or 'n' for no.\n");
        }
        sleep(1); // Giving a pause before the next request
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    User user;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    fgets(user.name, MAX_NAME_LENGTH, stdin);
    user.name[strcspn(user.name, "\n")] = 0; // Remove trailing newline

    pthread_t request_thread;
    pthread_create(&request_thread, NULL, request_fortune, &user);
    pthread_join(request_thread, NULL); // Wait for the request thread to finish

    printf("Thank you for visiting the fortune teller, %s!\n", user.name);
    return 0;
}