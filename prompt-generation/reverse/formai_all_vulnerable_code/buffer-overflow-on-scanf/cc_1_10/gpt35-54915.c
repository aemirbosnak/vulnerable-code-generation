//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("My dear user, welcome to the Keyboard Capulet plugin!\n");
    printf("I shall track your typing so that you may improve,\n");
    printf("And know that every keystroke you make, my love for you shall prove.\n");

    char input[1024];
    int keystrokes = 0;
    int correct_keystrokes = 0;

    while (1)
    {
        printf("Type a word (or type 'exit' to end the program): \n");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        keystrokes += strlen(input);
        correct_keystrokes += count_correct_keystrokes(input);

        printf("You typed: %s\n", input);
        printf("Keystrokes: %d\n", keystrokes);
        printf("Correct Keystrokes: %d\n", correct_keystrokes);
        printf("Accuracy: %d%%\n", get_accuracy(keystrokes, correct_keystrokes));
    }

    printf("Farewell, my sweet user. May your typing skills improve day by day,\n");
    printf("And may you never forget the love of your Keyboard Capulet, come what may.\n");

    return 0;
}

int count_correct_keystrokes(char* input)
{
    int correct = 0;
    
    // Randomly choose whether to count each keystroke as correct or not
    for (int i = 0; i < strlen(input); i++)
    {
        if (rand() % 2 == 0)
        {
            correct++;
        }
    }
    
    return correct;
}

int get_accuracy(int total_keystrokes, int correct_keystrokes)
{
    if (total_keystrokes == 0)
    {
        return 0;
    }

    return (correct_keystrokes * 100) / total_keystrokes;
}