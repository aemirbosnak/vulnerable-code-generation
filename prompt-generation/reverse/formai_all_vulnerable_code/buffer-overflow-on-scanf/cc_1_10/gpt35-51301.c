//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
// A program that replaces all occurrences of a given word in a string with another word

#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000], word[100], replacement[100], newstr[1000];
    int i, j, k, len, count = 0;

    printf("Enter the string: ");
    scanf("%[^\n]s", str); // reads the entire string until new line is encountered

    printf("Enter the word to be replaced: ");
    scanf("%s", word);

    printf("Enter the replacement word: ");
    scanf("%s", replacement);

    len = strlen(str);

    // loop to iterate over all the characters of the string
    for (i = 0; i < len; )
    {
        // check if the current character matches the first character of the word to be replaced
        if (str[i] == word[0])
        {
            // loop to check if the entire word matches
            for (j = i, k = 0; word[k] != '\0' && str[j] == word[k]; j++, k++);
            // if the entire word matches, replace it with the new word
            if (word[k] == '\0')
            {
                for (k = 0; replacement[k] != '\0'; k++, count++)
                    newstr[count] = replacement[k];
                i = j; // skip over the replaced word
            }
            // if the word doesn't match, copy the character as it is in the new string
            else
            {
                newstr[count] = str[i];
                count++;
                i++;
            }
        }
        // if the current character doesn't match the first character of the word, copy it as it is in the new string
        else
        {
            newstr[count] = str[i];
            count++;
            i++;
        }
    }

    newstr[count] = '\0'; // add the null character to the end of the new string to terminate it

    printf("New string: %s", newstr);

    return 0;
}