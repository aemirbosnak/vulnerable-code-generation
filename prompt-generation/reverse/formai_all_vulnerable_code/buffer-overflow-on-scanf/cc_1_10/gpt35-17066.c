//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
/* 
	Thou art entering the Disk Space Analyzer,
	Where thou shall be shown the size of thy files,
	And the grand total shall be thy heart's desire.

	But hark! Beware, for if thou hast little space,
	Thy heart shall break, and tears shall smudge thy face.

	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables for thy analysis:
    char filename[100];
    FILE *fp;
    long size = 0;
    long grand_total = 0;
    
    // Begin the dialog with thy user:
    printf("Good morrow! Welcome to the Disk Space Analyzer!\n");
    printf("Pray tell, what is the name of thy file or directory?\n");
    scanf("%s", filename);
    
    // Open thy file or directory and analyze its size:
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Oh sweet Jesu! Thou hast entered an invalid name!\n");
        printf("Please run the program again with a valid name.\n");
        return 0;
    }
    else
    {
        printf("Aha! Thy file or directory hath been found.\n");
        while (fgets(filename, 100, fp) != NULL)
        {
            size = strlen(filename) - 1;
            printf("The size of %s is %ld bytes.\n", filename, size);
            grand_total += size;
        }
        printf("And lo! The grand total is %ld bytes.\n", grand_total);
        fclose(fp);
    }
    
    // Bid farewell to thy user:
    printf("Farewell, and remember to keep thy disk space plentiful!\n");

    return 0;
}