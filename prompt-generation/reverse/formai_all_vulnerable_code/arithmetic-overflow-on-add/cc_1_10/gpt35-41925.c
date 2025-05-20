//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );

    return ch;
}

int main()
{
    printf("Welcome to the C Typing Speed Test!\n");
    printf("Type the following words as fast as you can:\n\n");

    char *words[] = {"programming", "language", "algorithm", "variable", "function", "array", "pointer", "debug", "compile", "execute"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int word_idx;

    srand(time(0));
    int seconds = 30;
    time_t end_time = time(0) + seconds;
    int score = 0;

    while (time(0) < end_time)
    {
        word_idx = rand() % num_words;
        printf("%s ", words[word_idx]);
        fflush(stdout);

        char input;
        while (1)
        {
            input = getch();
            if (input == words[word_idx][score])
            {
                score++;
                printf("%c", input);
                fflush(stdout);
            }
            else
            {
                printf("\nIncorrect. Try again.\n");
                fflush(stdout);
                break;
            }

            if (score == strlen(words[word_idx]))
            {
                score = 0;
                printf("\n");
                fflush(stdout);
                break;
            }
        }
    }

    printf("Test complete! Your typing speed is: %.2f words per minute.\n", (float)(num_words * (int)(seconds / 60)) / (float)(seconds / 60));
    return 0;
}