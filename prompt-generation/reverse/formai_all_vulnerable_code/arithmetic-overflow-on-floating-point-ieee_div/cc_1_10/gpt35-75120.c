//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {

    char text[100], temp;
    int i, j, count = 0, n, start_time, end_time, time_taken;
    float typing_speed;

    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin); //Take input from user

    n = strlen(text);
    for (i = 0; i < n; i++) {
        if (text[i] == ' ') {
            count++; //Count words
        }
    }

    printf("Type the above text:\n");

    start_time = time(NULL); //Start the timer

    for (i = 0; i < n; i++) {
        scanf("%c", &temp);
        if (temp == text[i]) {
            continue;
        }
        else { //If character doesn't match
            printf("Incorrect character! Try again!\n");
            i--;
        }
    }

    end_time = time(NULL); //End the timer

    time_taken = end_time - start_time; //Calculate time taken

    for (i = 0; i < n; i++) {
        if (text[i] != '\n' && text[i] != '\0') {
            text[i] = tolower(text[i]); //Convert text to lowercase
        }
    }

    printf("You typed %d words in %d seconds.\n", count + 1, time_taken);

    typing_speed = ((float)count + 1) / ((float)time_taken / 60); //Calculate typing speed

    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}