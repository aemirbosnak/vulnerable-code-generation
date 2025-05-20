//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int i, j, len, flag;

	printf("\n *************************************************\n");
	printf("\n* WELCOME TO THE PALINDROME CHECKER PUZZLE! *\n");
	printf("\n *************************************************\n\n");
	
	do
	{
		flag = 0; // Reset the flag
		
		// Prompt user for input
		printf("Please enter a string: ");
		scanf("%s", str);
		len = strlen(str);
		
		// Check if string is a palindrome
		for (i = 0, j = len - 1; i < len / 2; i++, j--)
		{
			if (str[i] != str[j])
			{
				flag = 1;
				break;
			}
		}

		// Display palindrome or not
		if (flag == 0)
		{
			printf("\n*********************************************************\n");
			printf("\n* Congratulations! \"%s\" is a palindrome! *\n", str);
			printf("\n*********************************************************\n\n");
		}
		else
		{
			printf("\n*********************************************************\n");
			printf("\n* Sorry, \"%s\" is not a palindrome. *\n", str);
			printf("\n*********************************************************\n\n");
			
			// Give a puzzling hint
			printf("\n[PUZZLE]:\n");
			printf("What is the same backwards and forwards but can also be read upside down and backwards?\n");
			printf("Think about it and try again!\n\n");
		}
	} while (flag != 0); // Keep prompting user until a palindrome is entered
	
	printf("Thanks for playing the Palindrome Checker Puzzle!\n");

	return 0;
}