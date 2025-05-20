//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main() {
    int i, j, correct = 0, total = 0, wpm;
    char text[1000], input[1000];
    time_t start, end;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following text as fast as you can.\n");
    printf("Press ENTER to start.\n\n");

    fgets(text, sizeof(text), stdin);
    printf("\n");

    printf("START TYPING:\n\n");

    time(&start);
    for(i = 0, j = 0; text[i] != '\0'; i++, j++) {
        printf("%c", text[i]);
        if(text[i] == '\n') j--;
    }
    fgets(input, sizeof(input), stdin);
    time(&end);

    for(i = 0; input[i] != '\0'; i++) {
        if(!isspace(input[i]))
            total++;
        if(input[i] == text[i])
            correct++;
    }

    wpm = total / (difftime(end, start) / 60);

    printf("\nRESULTS:\n\n");
    printf("Total Characters: %d\n", total);
    printf("Correct Characters: %d\n", correct);
    printf("Wrong Characters: %d\n", total - correct);
    printf("Typing Speed (WPM): %d\n\n", wpm);

    if(wpm > 100)
        printf("You are a typing master!\n");
    else if(wpm >= 70)
        printf("Impressive! You have a good typing speed.\n");
    else if(wpm >= 50)
        printf("Not too bad! Keep practicing to improve your typing speed.\n");
    else
        printf("You need to work on your typing speed. Keep practicing!\n");

    return 0;
}