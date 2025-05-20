//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Lines of code, oh how they dance!
    char line[100]; // Romeo, where art thou?
    int num_count = 0; // Alas, poor Yorick!
    double num_sum = 0.0; // My love for thee is like a floating point number!

    // Open the CSV file, dear reader.
    FILE *csvfile = fopen("example.csv", "r"); // O, speak again, bright angel!

    // Check if file exists, lest we perish.
    if (csvfile == NULL) // Wherefore art thou, file?
    {
        printf("Could not open file"); // Good pilgrim, you do wrong your hand too much.
        return 1; // Parting is such sweet sorrow.
    }

    // Read each line of the CSV, oh how they sing!
    while (fgets(line, 100, csvfile)) // How silver-sweet sound lovers' tongues by night!
    {
        char *token = strtok(line, ","); // Adieu, adieu, thy plaintive anthem fades

        while (token != NULL) // This bud of love, by summer's ripening breath may prove a beauteous flower when next we meet.
        {
            if (atof(token)) // By any other name would smell as sweet.
            {
                num_count++; // When he shall die, take him and cut him out in little stars.
                num_sum += atof(token); // I measure every grief I meet with narrow, probing eyes - I wonder if it weighs like mine - or has an easier size.
            }

            token = strtok(NULL, ","); // Parting is such sweet sorrow.
        }
    }

    // Close the CSV file, dear reader.
    fclose(csvfile); // Tis but thy name that is my enemy.

    // Calculate the average, oh how it gleams!
    double num_avg = num_sum / num_count; // Good night, good night! Parting is such sweet sorrow.

    printf("Sum: %f\n", num_sum); // It is the east, and Juliet is the sun.
    printf("Count: %d\n", num_count); // My bounty is as boundless as the sea, my love as deep; the more I give to thee, the more I have, for both are infinite.
    printf("Average: %f\n", num_avg); // Good night, good night! Parting is such sweet sorrow.

    return 0; // Parting is such sweet sorrow.
}