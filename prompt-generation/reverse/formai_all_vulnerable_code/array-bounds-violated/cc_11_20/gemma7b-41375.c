//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, suspicious_flag = 0;
    FILE *fp;

    fp = fopen("/home/user/mysecretfile.txt", "r");
    if (fp == NULL)
    {
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Check for suspicious characters
    for (i = 0; i < MAX_BUFFER_SIZE; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            for (j = i; buffer[j] >= 'a' && buffer[j] <= 'z'; j++)
            {
                // Counting consecutive letters
                k = 1;
                while (buffer[j] == buffer[j - 1] && k < 5)
                {
                    k++;
                    j++;
                }

                // If consecutive letters exceed the limit, set the suspicious flag
                if (k > 4)
                {
                    suspicious_flag = 1;
                }
            }
        }
    }

    // If the suspicious flag is set, alarm!
    if (suspicious_flag)
    {
        system("/bin/alarm");
    }

    fclose(fp);
    return 0;
}