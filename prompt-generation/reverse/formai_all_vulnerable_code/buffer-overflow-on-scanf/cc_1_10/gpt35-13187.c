//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_SPAM_WORDS 10

void add_spam_word(char *word, char spam_list[MAX_SPAM_WORDS][20], int *num_spam_words)
{
    if (*num_spam_words < MAX_SPAM_WORDS)
    {
        strcpy(spam_list[*num_spam_words], word);
        (*num_spam_words)++;
    }
    else
    {
        printf("Spam detection system error: Maximum spam words reached!\n");
    }
}

int check_for_spam(char *message, char spam_list[MAX_SPAM_WORDS][20], int num_spam_words)
{
    char *token;
    char delimiters[] = " ,.?!";
    int spam_word_count = 0;

    token = strtok(message, delimiters);

    while (token != NULL)
    {
        for (int i=0; i<num_spam_words; i++)
        {
            if (strcmp(token, spam_list[i]) == 0)
            {
                spam_word_count++;
            }
        }

        if (spam_word_count >= 2)
        {
            return 1;
        }

        token = strtok(NULL, delimiters);
    }

    return 0;
}

int main()
{
    char message[100];
    char spam_list[MAX_SPAM_WORDS][20];
    int num_spam_words = 0;

    printf("Welcome to the Spam Detection System!\n\n");
    printf("Enter up to %d spam words to detect (one at a time):\n\n", MAX_SPAM_WORDS);

    while (num_spam_words < MAX_SPAM_WORDS)
    {
        printf("Enter spam word %d: ", num_spam_words+1);
        scanf("%s", spam_list[num_spam_words]);
        num_spam_words++;

        if (num_spam_words == MAX_SPAM_WORDS)
        {
            printf("\nYou have reached the limit of %d spam words.\n\n", MAX_SPAM_WORDS);
        }
        else
        {
            printf("\nEnter another spam word? (y/n): ");

            char response;
            scanf(" %c", &response);

            if (response != 'y' && response != 'Y')
            {
                break;
            }
        }
    }

    printf("\nEnter a message to check for spam:\n\n");
    scanf(" ");
    fgets(message, 100, stdin);

    int is_spam = check_for_spam(message, spam_list, num_spam_words);

    if (is_spam)
    {
        printf("\n\nSPAM DETECTED!!!\n\n");
    }
    else
    {
        printf("\n\nNo spam detected. Message is safe to send.\n\n");
    }

    return 0;
}