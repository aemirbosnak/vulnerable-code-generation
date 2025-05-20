//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_COLOR_LEN 20

// Struct to store user information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char favorite_color[MAX_COLOR_LEN];
} UserInfo;

// Function to generate a fortune based on user information
const char* generate_fortune(UserInfo user) {
    // Based on age, determine fortune category
    const char* fortune_category;
    if (user.age < 18) {
        fortune_category = "future scholar";
    } else if (user.age < 30) {
        fortune_category = "young professional";
    } else if (user.age < 50) {
        fortune_category = "mid-career magician";
    } else {
        fortune_category = "wise sage";
    }

    // Generate fortune based on favorite color
    const char* fortune;
    if (strcmp(user.favorite_color, "red") == 0) {
        fortune = "Your passion will ignite like a fiery sunset.";
    } else if (strcmp(user.favorite_color, "orange") == 0) {
        fortune = "Your creativity will be as vibrant as an autumn leaf.";
    } else if (strcmp(user.favorite_color, "green") == 0) {
        fortune = "Your growth will be as abundant as a lush forest.";
    } else if (strcmp(user.favorite_color, "blue") == 0) {
        fortune = "Your calmness will be as tranquil as a deep, clear sea.";
    } else if (strcmp(user.favorite_color, "purple") == 0) {
        fortune = "Your imagination will be as boundless as the cosmos.";
    } else {
        fortune = "Your uniqueness will shine like a rainbow.";
    }

    // Combine fortune category and fortune
    static char fortune_str[256];
    snprintf(fortune_str, sizeof(fortune_str), "%s %s.", fortune_category, fortune);

    return fortune_str;
}

int main() {
    UserInfo user;

    printf("Greetings, traveler! Welcome to the mystical realm of the fortune teller!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);

    printf("How old are you, dear one? ");
    scanf("%d", &user.age);

    printf("And what is your favorite color? ");
    scanf("%s", user.favorite_color);

    // Call fortune generation function and print result
    const char* fortune = generate_fortune(user);
    printf("\n%s\n", fortune);

    printf("Your journey continues, may your future be bright and filled with wonder!\n");

    return 0;
}