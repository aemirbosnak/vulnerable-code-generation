//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating = 0;
    char genre;
    char quality;

    printf("Good evening, dear reader, and welcome to the illustrious office of Sherlock Holmes.\n");
    printf("Please tell me the genre of the movie you wish to discuss: ");
    scanf("%c", &genre);

    printf("And what is the quality of the movie in your opinion? (A, B, C): ");
    scanf("%c", &quality);

    switch (genre)
    {
        case 'A':
            switch (quality)
            {
                case 'A':
                    rating = 9;
                    break;
                case 'B':
                    rating = 8;
                    break;
                case 'C':
                    rating = 7;
                    break;
            }
            break;
        case 'B':
            switch (quality)
            {
                case 'A':
                    rating = 8;
                    break;
                case 'B':
                    rating = 7;
                    break;
                case 'C':
                    rating = 6;
                    break;
            }
            break;
        case 'C':
            switch (quality)
            {
                case 'A':
                    rating = 7;
                    break;
                case 'B':
                    rating = 6;
                    break;
                case 'C':
                    rating = 5;
                    break;
            }
            break;
    }

    printf("Based on your input, I have determined that the movie's rating is: %d\n", rating);
    return 0;
}