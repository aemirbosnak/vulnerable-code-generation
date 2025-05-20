//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char path[100];

    printf("Enter path to analyze: ");
    scanf("%s", path);

    system("df -k > diskspace.txt");

    FILE *input = fopen("diskspace.txt", "r");
    if (!input)
    {
        perror("Error opening file");
        exit(1);
    }

    char line[100], temp[10];
    int i = 1, total = 0;
    printf("\n%-15s %-15s %-15s\n", "Device", "Size[KB]", "Used[KB]");

    while (fgets(line, 100, input) != NULL)
    {
        if (i != 1)
        {
            int count = 0, j = 0, k = 0;
            char device[20], size[20], used[20];
            while (line[count] != '\0')
            {
                if (line[count] == ' ')
                {
                    j++;
                }
                else if (j == 0)
                {
                    device[k] = line[count];
                    k++;
                }
                else if (j == 1)
                {
                    size[k] = line[count];
                    k++;
                }
                else if (j == 2)
                {
                    used[k] = line[count];
                    k++;
                }
                count++;
            }
            device[k] = '\0';
            size[k] = '\0';
            used[k] = '\0';

            int dev_len = strlen(device), path_len = strlen(path);
            if (path_len > dev_len)
            {
                continue;
            }

            int flag = 0;
            for (int j = 0; j < path_len; j++)
            {
                if (path[j] != device[j])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("%-15s %-15s %-15s\n", device, size, used);
                total += atoi(size);
            }
        }
        i++;
    }

    printf("\nTotal disk space used by %s: %d KB\n", path, total);

    return 0;
}