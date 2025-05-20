//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include<stdio.h>

#define MAX_LENGTH 1000

void reverse(char s[], int length)
{
    int i, j;
    char temp;
    for (i = 0, j = length-1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int digits(int num)
{
    int count = 0;
    do
    {
        count++;
        num /= 10;
    } while (num > 0);
    return count;
}

void print_seq(char seq[][MAX_LENGTH], int seq_count, int seq_len)
{
    int i, j;
    for (i = 0; i < seq_count; i++)
    {
        reverse(seq[i], seq_len);
        printf("Sequence %d: %s\n", i+1, seq[i]);
    }
}

int main()
{
    int seq_len, seq_count, i, j;
    char seq[MAX_LENGTH];
    printf("Enter the length of genome sequence: ");
    scanf("%d", &seq_len);
    printf("Enter the number of sequences: ");
    scanf("%d", &seq_count);
    char genome[seq_count][MAX_LENGTH];
    for (i = 0; i < seq_count; i++)
    {
        int num = i+1;
        char num_str[digits(num) + 1];
        sprintf(num_str, "%d", num);
        int num_str_len = digits(num);
        for (j = 0; j < seq_len; j++)
        {
            char c = 'A' + rand() % 4;
            seq[j] = c;
        }
        seq[j] = '\0';
        reverse(seq, seq_len);
        strcpy(genome[i], seq);
        strcat(genome[i], num_str);
    }
    print_seq(genome, seq_count, seq_len+1);
    return 0;
}