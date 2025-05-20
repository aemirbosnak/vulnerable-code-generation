//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    char email[50];
    printf("Enter your email address: ");
    scanf("%s", email);

    int vowelCount = 0;
    int consonantCount = 0;
    int digitCount = 0;
    int specialCharCount = 0;

    for (int i = 0; i < strlen(email); i++)
    {
        char ch = email[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vowelCount++;
            }
            else
            {
                consonantCount++;
            }
        }
        else if (ch >= '0' && ch <= '9')
        {
            digitCount++;
        }
        else
        {
            specialCharCount++;
        }
    }

    int totalChars = vowelCount + consonantCount + digitCount + specialCharCount;
    float vowelPercentage = (float)vowelCount / totalChars * 100;
    float digitPercentage = (float)digitCount / totalChars * 100;
    float specialCharPercentage = (float)specialCharCount / totalChars * 100;

    printf("\nYour email address contains:\n");
    printf("- %d vowels (%.2f%%)\n", vowelCount, vowelPercentage);
    printf("- %d digits (%.2f%%)\n", digitCount, digitPercentage);
    printf("- %d special characters (%.2f%%)\n", specialCharCount, specialCharPercentage);

    if (vowelPercentage > 40 || digitPercentage > 20 || specialCharPercentage > 10)
    {
        printf("\nWARNING: Your email address looks like spam! Please check it again!\n");
    }
    else
    {
        printf("\nGreat! Your email address doesn't look like spam!\n");
    }

    return 0;
}