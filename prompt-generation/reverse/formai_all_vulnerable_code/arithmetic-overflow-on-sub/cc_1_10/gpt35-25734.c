//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void shuffle(char* array, int n) {
    srand(time(NULL));
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void display(char* arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
}

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the characters as they appear on the screen and hit enter.\n");
    printf("Press Enter to start the test!\n");

    getchar();

    int count = 0;
    char ch, input[100];
    clock_t time_start, time_end;

    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int n = sizeof(letters)/sizeof(letters[0]);

    shuffle(letters, n);

    display(letters, n);

    time_start = clock();

    while(count < n) {
        ch = getchar();
        if(ch != '\n') {
            input[count] = ch;
            count++;
        }
    }

    time_end = clock();

    float elapsed_time = (float) (time_end - time_start) / CLOCKS_PER_SEC;

    printf("\n\nYou typed: %s\n", input);

    int mistakes = 0;

    for(int i = 0; i < n; i++) {
        if(input[i] != letters[i]) {
            mistakes++;
        }
    }

    int accuracy = ((n - mistakes) * 100) / n;

    printf("\nYour accuracy: %d%c\n", accuracy, 37);

    int wpm = (float) (n / elapsed_time) * 60 / 5;

    printf("Your typing speed: %d WPM\n", wpm);

    return 0;
}