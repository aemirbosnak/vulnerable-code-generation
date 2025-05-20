//FormAI DATASET v1.0 Category: String manipulation ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[1000], word[100], replacement[100];
    int i, j, k, len1, len2, len3;
    printf("Hi there! I'm the string manipulation master!\n");
    printf("Give me a sentence and I'll show you the power of my code! \n");

    fgets(sentence, 1000, stdin);
    len1 = strlen(sentence);

    printf("Now, tell me a word in the sentence you would like to replace: ");
    scanf("%s", word);
    len2 = strlen(word);

    printf("What would you like to replace it with?: ");
    scanf("%s", replacement);
    len3 = strlen(replacement);

    for (i = 0; i < len1; i++)
    {
        if (sentence[i] == word[0])
        {
            for (j = i, k = 0; k < len2; j++, k++)
            {
                if (sentence[j] != word[k])
                {
                    break;
                }
            }
            if (k == len2)
            {
                for (k = i; k < i + len3; k++)
                {
                    sentence[k] = replacement[k - i];
                }
            }
        }
    }

    printf("\n\nYour sentence with the new replacement is now: %s", sentence);

    printf("\n\nDon't you love my string manipulation skills?\n");
    printf("Without me, your sentences would remain boring and dull.\n");
    printf("But with me, your sentences will always be fun, exciting, and never null.\n");

    return 0;
}