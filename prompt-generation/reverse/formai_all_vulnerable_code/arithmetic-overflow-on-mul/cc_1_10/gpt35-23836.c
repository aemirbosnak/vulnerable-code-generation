//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int milliseconds) {
    long pause;
    clock_t now,then;
  
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while((now-then) < pause)
        now = clock();
}

int main() {
    char prompt[100] = "Are you ready to test your typing speed? Press ENTER to start the test.";
    char type[100];
    int time_taken, num_words = 0, i, j = 0;
    clock_t start, end;
  
    // Prompt user to start the test
    printf("%s", prompt);
    getchar();
  
    // Display starting message
    printf("The test has begun. Type the following text as quickly and accurately as possible:\n");
    char test_text[] = "Roses are red, violets are blue, sugar is sweet, and so are you.";
    printf("\n%s\n\n", test_text);
  
    // Start timer
    start = clock();
  
    // Get user input
    fgets(type, 100, stdin);
  
    // End timer
    end = clock();
  
    // Calculate time taken
    time_taken = (int)(end - start) * 1000 / CLOCKS_PER_SEC;
  
    // Calculate number of words typed
    for(i=0;i<strlen(test_text);i++){
        if(test_text[i]==' '){
            num_words++;
        }
    }
    num_words++;
  
    // Display results
    printf("\nYou took %d milliseconds to finish typing the text.\n", time_taken);
    printf("You typed %d words in total.\n", num_words);
    printf("Your typing speed is %d words per minute.\n", (int)((float)num_words / time_taken * 1000 * 60));
  
    // Display romantic message
    delay(3000);
    printf("\nLove is like typing, it takes time and practice. But eventually, with determination and persistence, you will get better at it. Keep typing, my love, and never give up.\n");
  
    return 0;
}