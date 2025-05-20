//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[] = "A fog hung thick in the air, obscuring the view of the quaint village of Crickley Hall. The mist crept and roared, casting long, ominous shadows upon the crumbling estate.";

    // Extract metadata from the text
    char author[20];
    char date[20];
    char genre[20];

    // Analyze the text for author, date, and genre
    int i = 0;
    while (text[i] != '\0')
    {
        // Author
        if (text[i] == 'A' && text[i+1] == 'u')
        {
            char authorStart = text[i+2];
            char authorEnd = text[i+3];
            strcpy(author, text+authorStart-2);
            authorEnd = authorStart - 2;
            for (int j = authorStart; j <= authorEnd; j++)
            {
                author[j - authorStart] = toupper(author[j - authorStart]);
            }
        }

        // Date
        if (text[i] == 'T' && text[i+1] == 'h')
        {
            char dateStart = text[i+2];
            char dateEnd = text[i+3];
            strcpy(date, text+dateStart-2);
            dateEnd = dateStart - 2;
            for (int j = dateStart; j <= dateEnd; j++)
            {
                date[j - dateStart] = toupper(date[j - dateStart]);
            }
        }

        // Genre
        if (text[i] == 'G' && text[i+1] == 'en')
        {
            char genreStart = text[i+2];
            char genreEnd = text[i+3];
            strcpy(genre, text+genreStart-2);
            genreEnd = genreStart - 2;
            for (int j = genreStart; j <= genreEnd; j++)
            {
                genre[j - genreStart] = toupper(genre[j - genreStart]);
            }
        }

        i++;
    }

    // Print the extracted metadata
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);
    printf("Genre: %s\n", genre);

    return 0;
}