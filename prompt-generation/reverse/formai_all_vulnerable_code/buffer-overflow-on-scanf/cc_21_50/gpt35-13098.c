//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dictionary[] = {"banana", "apple", "pear", "orange", "grape", "pineapple", "watermelon", "kiwi", "strawberry", "blueberry"};

int main()
{
    char input[50];
    int i, j, k, l;
    int len, found, count;

    while(1)
    {
        printf("\nEnter a word to check the spelling: ");
        scanf("%s", input);

        len = strlen(input);

        if(len == 0)
        {
            printf("You didn't enter anything. Please try again.");
        }
        else
        {
            found = 0;

            for(i=0; i<10; i++) // check against the dictionary
            {
                if(strcmp(input, dictionary[i]) == 0)
                {
                    printf("The spelling of \"%s\" is correct. Congratulations, you know how to spell \"%s\"!\n", input, input);
                    found = 1;
                    break;
                }
            }

            if(found == 0) // check for common errors
            {
                printf("Oops, it looks like you may have misspelled \"%s\". Here are some suggestions:\n", input);

                count = 0;

                // swap adjacent letters
                for(i=0; i<len-1; i++)
                {
                    char temp = input[i];
                    input[i] = input[i+1];
                    input[i+1] = temp;

                    for(j=0; j<10; j++)
                    {
                        if(strcmp(input, dictionary[j]) == 0)
                        {
                            printf("%s\n", input);
                            count++;
                            break;
                        }
                    }

                    temp = input[i];
                    input[i] = input[i+1];
                    input[i+1] = temp;
                }

                // remove one letter
                for(i=0; i<len; i++)
                {
                    for(j=0; j<10; j++)
                    {
                        k = 0;
                        l = 0;

                        while(input[k] != '\0' && dictionary[j][l] != '\0')
                        {
                            if(input[k] != dictionary[j][l])
                            {
                                break;
                            }

                            k++;
                            l++;
                        }

                        if(dictionary[j][l] == '\0' && input[k] == '\0')
                        {
                            printf("%s\n", dictionary[j]);
                            count++;
                        }
                    }
                }

                // add one letter
                for(i=0; i<len+1; i++)
                {
                    for(j=0; j<26; j++) // try all letters
                    {
                        char temp[50];

                        for(k=0; k<i; k++)
                        {
                            temp[k] = input[k];
                        }

                        temp[i] = j+97; // 97 is the ASCII code for 'a'

                        for(l=i; l<len; l++)
                        {
                            temp[l+1] = input[l];
                        }

                        temp[len+1] = '\0';

                        for(k=0; k<10; k++)
                        {
                            if(strcmp(temp, dictionary[k]) == 0)
                            {
                                printf("%s\n", temp);
                                count++;
                                break;
                            }
                        }
                    }
                }

                if(count == 0)
                {
                    printf("Sorry, we couldn't find any similar words.\n");
                }
                else
                {
                    printf("\nDon't worry, we've got you covered. Keep up the good work!\n");
                }
            }
        }
    }

    return 0;
}