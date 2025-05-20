//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define NAME_LEN 30

void convert_temperature(float temp, char type) {
    if (type == 'C' || type == 'c') {
        float fahrenheit = (temp * 9.0 / 5.0) + 32;
        printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
    } else if (type == 'F' || type == 'f') {
        float celsius = (temp - 32) * 5.0 / 9.0;
        printf("Temperature in Celsius: %.2f°C\n", celsius);
    } else {
        printf("Invalid temperature type entered!\n");
    }
}

int main() {
    char user_names[MAX_USERS][NAME_LEN];
    float temperatures[MAX_USERS];
    char types[MAX_USERS];
    int user_count = 0, exit = 0;

    while (user_count < MAX_USERS && !exit) {
        char name[NAME_LEN];

        printf("Enter your name (or type 'exit' to leave): ");
        fgets(name, NAME_LEN, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline

        if (strcmp(name, "exit") == 0) {
            exit = 1;
            break;
        }

        strcpy(user_names[user_count], name);

        printf("Hello, %s! Enter the temperature: ", user_names[user_count]);
        scanf("%f", &temperatures[user_count]);
        getchar(); // To consume the newline after the number input

        printf("Is this temperature in Celsius or Fahrenheit? (C/F): ");
        scanf("%c", &types[user_count]);
        getchar(); // To consume the newline

        convert_temperature(temperatures[user_count], types[user_count]);

        user_count++;
        printf("\n");
    }

    printf("Session ended. The records of users are:\n");
    for (int i = 0; i < user_count; i++) {
        printf("User: %s | Temperature: %.2f | Type: %c\n", user_names[i], temperatures[i], types[i]);
    }

    return 0;
}