//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100] = "Hello, I'm a curious chatbot!";
    char question[50] = "How many vowels are in this sentence?";
    char answer[10];

    printf("%s\n", message);
    printf("%s\n", question);

    scanf("%s", answer);

    int count = 0;

    for(int i=0; i<strlen(message); i++)
    {
        if(message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' ||
           message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U')
        {
            count++;
        }
    }

    printf("The number of vowels in the sentence is %d\n", count);

    int length = strlen(message);
    char reverse[100];

    for(int i=0; i<length; i++)
    {
        reverse[i] = message[length-i-1];
    }

    reverse[length] = '\0';

    printf("The sentence in reverse is: %s\n", reverse);

    char upper[100];

    for(int i=0; i<strlen(message); i++)
    {
        upper[i] = toupper(message[i]);
    }

    upper[strlen(message)] = '\0';

    printf("The sentence in all uppercase: %s\n", upper);

    char lower[100];

    for(int i=0; i<strlen(message); i++)
    {
        lower[i] = tolower(message[i]);
    }

    lower[strlen(message)] = '\0';

    printf("The sentence in all lowercase: %s\n", lower);

    if(strcmp(lower, upper) == 0)
    {
        printf("The sentence is already in all uppercase and all lowercase.\n");
    }
    else
    {
        printf("The sentence is not already in all uppercase and all lowercase.\n");
    }

    return 0;
}