//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    long double a[64], b[64], c[64], d[64], e[64];
    FILE* fp;
    int i;
    char* cmd = "top -b -n1 | grep \"Cpu(s)\" | awk '{print $2 + $4}'";
    
    while(1)
    {
        fp = popen(cmd, "r");
        if(fp == NULL)
        {
            printf("Error in opening pipe.\n");
            exit(1);
        }
        
        i = 0;
        while(fscanf(fp, "%Lf", &a[i]) != EOF)
        {
            i++;
        }
        
        pclose(fp);
        
        b[0] = a[0];
        c[0] = b[0] / 100;
        for(i = 1; i < 64; i++)
        {
            d[i] = a[i] - a[i - 1];
            e[i] = d[i] / 100;
            b[i] = b[i - 1] + e[i];
            c[i] = b[i] / (i + 1);
        }
        
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
        printf("CPU Usage Monitor:\n");
        printf("-----------------------------------\n");
        printf("|  ");
        for(i = 0; i < 64; i++)
        {
            printf("%c", (i % 8 == 0) ? '|' : '-');
        }
        printf("\n|  ");
        for(i = 0; i < 64; i++)
        {
            printf("%c", (i % 8 == 0) ? '|' : ' ');
        }
        printf("\n|");
        for(i = 0; i < 64; i++)
        {
            printf("%c", (i % 8 == 0) ? '+' : '-');
        }
        printf("\n|");
        for(i = 0; i < 64; i++)
        {
            printf("%c", (i % 8 == 0 && c[i] < 0.125) ? '|' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.125 && c[i] < 0.25) ? '.' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.25 && c[i] < 0.375) ? ':' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.375 && c[i] < 0.5) ? '-' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.5 && c[i] < 0.625) ? '=' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.625 && c[i] < 0.75) ? '+' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.75 && c[i] < 0.875) ? '*' : ' ');
            printf("%c", (i % 8 == 0 && c[i] >= 0.875) ? '#' : ' ');
        }
        printf("\n");
        printf("-----------------------------------\n");
        printf("| Time (sec): ");
        for(i = 0; i < 6; i++)
        {
            printf("%d", i);
        }
        for(i = 6; i < 64; i++)
        {
            printf("%d", i - 60);
        }
        printf("\n");
        printf("-----------------------------------\n");
        printf("| CPU Usage:");
        for(i = 0; i < 64; i++)
        {
            printf(" %.2Lf%%", c[i] * 100);
        }
        printf("\n");
        
        sleep(1);
    }
    
    return 0;
}