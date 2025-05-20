//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>

// Function to compare two strings lexicographically
int stringCompare(char str1[], char str2[]) {
    for(int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if(str1[i] != str2[i])
            return 0;
    }
    return 1;
}

// Function to calculate the sum of two numbers
int sum(int a, int b) {
    return a + b;
}

int main() {
    char name[20];
    int age, yearOfBirth, currentYear;
    char favoriteColor[10];

    printf("Hello! Welcome to our love calculator.\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter the year of your birth (YYYY): ");
    scanf("%d", &yearOfBirth);
    printf("Please enter the current year (YYYY): ");
    scanf("%d", &currentYear);
    printf("Please enter your favorite color: ");
    scanf("%s", favoriteColor);

    // Calculate the age and check if the person is above 18 years old
    int calculatedAge = currentYear - yearOfBirth;
    if(calculatedAge < 18) {
        printf("We're sorry but you must be 18 years or older to use this calculator.\n");
        return 0;
    }

    // Check if the person's favorite color is red
    if(stringCompare(favoriteColor, "red")) {
        printf("Oh, I see you like the color red. That's my favorite color too!\n");
    }

    printf("Great! Now, let's see if we're compatible...\n");
    printf("Please enter your partner's name: ");

    // Get the partner's name and compare it to the user's name
    char partnerName[20];
    scanf("%s", partnerName);
    if(stringCompare(name, partnerName)) {
        printf("Sorry but you can't be in a relationship with yourself.\n");
        return 0;
    }

    printf("Please enter your partner's favorite color: ");
    char partnerFavColor[10];
    scanf("%s", partnerFavColor);

    // Check if the partner's favorite color is the same as the user's favorite color
    if(stringCompare(favoriteColor, partnerFavColor)) {
        printf("Wow, you and your partner have the same favorite color! That's a good sign.\n");
    }

    printf("Please enter your partner's age: ");
    int partnerAge;
    scanf("%d", &partnerAge);

    // Calculate the partner's age and check if they are above 18 years old
    int calculatedPartnerAge = currentYear - partnerAge;
    if(calculatedPartnerAge < 18) {
        printf("Sorry but your partner must be 18 years or older to use this calculator.\n");
        return 0;
    }

    // Calculate the sum of the user's age and the partner's age
    int totalAge = sum(age, partnerAge);

    printf("\n\nCongratulations %s! You and your partner have a total age of %d. That's a great sign of compatibility!\n\n", name, totalAge);

    return 0;
}