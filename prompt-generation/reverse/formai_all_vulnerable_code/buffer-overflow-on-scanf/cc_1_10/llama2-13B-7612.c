//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024

int main() {
    int age;
    char name[MAX_STRING_LENGTH];

    // Ask the user for their name and age
    printf("What is your name? ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    printf("How old are you? ");
    scanf("%d", &age);

    // Check if the user entered a valid name
    if (strlen(name) > MAX_STRING_LENGTH) {
        printf("Error: Your name is too long. Please enter a name with at most %d characters.\n", MAX_STRING_LENGTH);
        return 1;
    }

    // Check if the user entered a valid age
    if (age < 0 || age > 100) {
        printf("Error: Your age must be a positive integer between 0 and 100. Please enter a valid age.\n");
        return 1;
    }

    // Generate a random message based on the user's age
    if (age < 20) {
        printf("Congratulations, you're still young and carefree! Here's your message:");
        sleep(1); // simulate a short pause
        printf("You're a cool cat who loves to party all night long! 😻🎉\n");
    } else if (age >= 20 && age < 50) {
        printf("Congratulations, you're in your prime! Here's your message:");
        sleep(2); // simulate a moderate pause
        printf("You're a wise and experienced individual who knows how to get things done! 😊👍\n");
    } else if (age >= 50 && age < 80) {
        printf("Congratulations, you're a seasoned veteran! Here's your message:");
        sleep(3); // simulate a longer pause
        printf("You're a wise and gentle soul who has seen it all and knows the importance of family and friends! 😌👪\n");
    } else {
        printf("Congratulations, you're a wise and venerable elder! Here's your message:");
        sleep(4); // simulate a very long pause
        printf("You're a source of wisdom and guidance for the younger generations. Your life experience is a treasure trove of knowledge and insight! 😢👵\n");
    }

    return 0;
}