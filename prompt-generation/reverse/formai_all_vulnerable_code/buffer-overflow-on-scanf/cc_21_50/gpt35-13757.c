//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char password[50];
	int length, upper_count, lower_count, num_count, sym_count, difficulty;
	upper_count = lower_count = num_count = sym_count = difficulty = 0;

	printf("*** Welcome to the Medieval Password Strength Checker! ***\n");
	printf("Please enter your password: ");
	scanf("%s", password);

	length = strlen(password);
	
	for(int i = 0; i < length; i++)
	{
		if(isupper(password[i]))
			upper_count++;
		if(islower(password[i]))
			lower_count++;
		if(isdigit(password[i]))
			num_count++;
		if(!isdigit(password[i]) && !isalpha(password[i]))
			sym_count++;
	}

	if(upper_count > 0 && lower_count > 0 && num_count > 0 && sym_count > 0)
		difficulty++;
	if(length >= 8 && length < 12)
		difficulty++;
	if(length >= 12 && length < 16)
		difficulty += 2;
	if(length >= 16)
		difficulty += 3;

	printf("Checking your password...\n");
	printf("Your password: %s\n", password);
	printf("Length: %d\n", length);
	printf("Uppercase letters: %d\n", upper_count);
	printf("Lowercase letters: %d\n", lower_count);
	printf("Numbers: %d\n", num_count);
	printf("Symbols: %d\n", sym_count);

	switch(difficulty)
	{
		case 0:
			printf("Your password is too weak. It would not last a day in medieval times!");
			break;
		case 1:
			printf("Your password is weak. Any good knight would be able to guess it!");
			break;
		case 2:
			printf("Your password is decent. It would take a skilled thief to crack it!");
			break;
		case 3:
			printf("Your password is strong. Only a wizard of great power could break it!");
			break;
		case 4:
			printf("Your password is very strong. No dragon would be able to destroy it!");
			break;
		case 5:
			printf("Your password is unbreakable. You are a champion of password strength!");
			break;
	}

	return 0;
}