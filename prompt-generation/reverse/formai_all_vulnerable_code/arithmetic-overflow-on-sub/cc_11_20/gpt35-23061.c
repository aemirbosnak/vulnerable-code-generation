//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: authentic
#include<stdio.h>
#include<string.h>

void main()
{
    int i, j, k, l, m;
    char str[100][100], temp[100];

    // Get input from user
    printf("Enter the number of strings:");
    scanf("%d", &l);

    printf("Enter the strings:");
    for(i=0; i<l; i++)
    {
        scanf("%s", str[i]);
    }

    // Sort the strings using bubble sort
    for(i=0; i<l; i++)
    {
        for(j=i+1; j<l; j++)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    // Print the sorted strings
    printf("Sorted strings are:\n");
    for(i=0; i<l; i++)
    {
        printf("%s\n", str[i]);
    }

    // Check for intrusion detection
    printf("Checking for intrusion detection...\n");
    for(i=0; i<l-1; i++)
    {
        for(j=i+1; j<l; j++)
        {
            if(strlen(str[i])==strlen(str[j])) // Check for strings of same length
            {
                m = strlen(str[i]);
                k = 0;
                while(k<m)
                {
                    if(str[i][k]!=str[j][k]) // Check for character mismatch
                    {
                        break;
                    }
                    k++;
                }
                if(k==m)
                {
                    printf("Intrusion Detected: \"%s\" is similar to \"%s\".\n", str[i], str[j]);
                }
            }
        }
    }
}