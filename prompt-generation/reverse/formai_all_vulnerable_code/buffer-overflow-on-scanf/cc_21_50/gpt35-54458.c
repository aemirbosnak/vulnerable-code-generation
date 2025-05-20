//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Romeo and Juliet
// A Password Strength Checker in Romeo and Juliet Style

#include <stdio.h>
#include <string.h>

int main() 
{
  char password[100];
  int i, length, digits = 0, letters = 0, upper_case = 0, lower_case = 0, special_characters = 0;

  // Romeo: Good morrow Juliet, what task dost thou undertake?
  printf("Romeo: Good morrow Juliet, what task dost thou undertake?\n");
  printf("Juliet: Fair Romeo, I am creating a password strength checker.\n");
  printf("Romeo: Ah, fair maiden, I doth offer thee my assistance.\n");
  printf("Juliet: Thank thee, dear Romeo. I would be most grateful.\n");

  // Romeo: Pray, tell me, what manner of password dost thou wish to check?
  printf("Romeo: Pray, tell me, what manner of password dost thou wish to check?\n");
  printf("Juliet: Any password that be entered by the user, good sir.\n");

  // Romeo: Very well, let us proceed with the task at hand.
  printf("Romeo: Very well, let us proceed with the task at hand.\n");
  printf("Juliet: Thank thee, Romeo. Pray, how shall we approach this task?\n");

  // Romeo: Firstly, we shall ask the user for their password.
  printf("Romeo: Firstly, we shall ask the user for their password.\n");
  printf("Juliet: Aye, verily. How shall we do this?\n");

  // Romeo: We shall use the scanf function to receive input from the user.
  printf("Romeo: We shall use the scanf function to receive input from the user.\n");
  printf("Juliet: Excellent. Pray, continue.\n");

  // Romeo: Secondly, we shall check the length of the password.
  printf("Romeo: Secondly, we shall check the length of the password.\n");
  printf("Juliet: I see. If the password be too short, it be easy to guess.\n");
  printf("Romeo: Aye, that is so. We shall make sure that the password be at least 8 characters long.\n");

  // Romeo: Let us proceed with the code.
  printf("Romeo: Let us proceed with the code.\n");
  printf("Juliet: Aye, verily.\n");

  // Prompt the user to enter their password
  printf("Enter your password: ");
  scanf("%s", password);
  
  // Check the length of the password
  length = strlen(password);
  
  // Romeo: We must ensure that the password be at least 8 characters long.
  printf("Romeo: We must ensure that the password be at least 8 characters long.\n");
  printf("Juliet: Verily. Continuest thou the code, then.\n");

  // Check if the password meets the length requirement
  if (length < 8) 
  {
    printf("Password is too short. Please enter a password of at least 8 characters.\n");
    return 0;
  }
  
  // Romeo: Now, we shall check the strength of the password.
  printf("Romeo: Now, we shall check the strength of the password.\n");
  printf("Juliet: Aye, fair Romeo. Pray, how shall we go about this?\n");

  // Romeo: We shall examine each character of the password and determine its type.
  printf("Romeo: We shall examine each character of the password and determine its type.\n");
  printf("Juliet: I see. And how shall we do this?\n");

  // Romeo: We shall loop through the characters of the password and check each one.
  printf("Romeo: We shall loop through the characters of the password and check each one.\n");
  printf("Juliet: Excellent. Proceed, then.\n");

  for (i = 0; i < length; i++) 
  {
    // Check if the character is a digit
    if (password[i] >= '0' && password[i] <= '9') 
    {
      digits++;
    }
    
    // Check if the character is a letter
    if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) 
    {
      letters++;
    }
    
    // Check if the character is an uppercase letter
    if (password[i] >= 'A' && password[i] <= 'Z') 
    {
      upper_case++;
    }
    
    // Check if the character is a lowercase letter
    if (password[i] >= 'a' && password[i] <= 'z') 
    {
      lower_case++;
    }
    
    // Check if the character is a special character
    if (!((password[i] >= '0' && password[i] <= '9') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z'))) 
    {
      special_characters++;
    }
  }
  
  // Romeo: Now that we have checked each character of the password, we shall determine its strength.
  printf("Romeo: Now that we have checked each character of the password, we shall determine its strength.\n");
  printf("Juliet: Aye, verily. And how shall we do this?\n");

  // Romeo: We shall check the number and types of characters in the password.
  printf("Romeo: We shall check the number and types of characters in the password.\n");
  printf("Juliet: Excellent. Proceed, then.\n");

  // Check if the password contains at least one digit
  if (digits == 0) 
  {
    printf("Password must contain at least one digit.\n");
    return 0;
  }
  
  // Check if the password contains at least one letter
  if (letters == 0) 
  {
    printf("Password must contain at least one letter.\n");
    return 0;
  }
  
  // Check if the password contains at least one uppercase letter
  if (upper_case == 0) 
  {
    printf("Password must contain at least one uppercase letter.\n");
    return 0;
  }
  
  // Check if the password contains at least one lowercase letter
  if (lower_case == 0) 
  {
    printf("Password must contain at least one lowercase letter.\n");
    return 0;
  }
  
  // Check if the password contains at least one special character
  if (special_characters == 0) 
  {
    printf("Password must contain at least one special character.\n");
    return 0;
  }

  // Romeo: The password meeteth all requirements. Thou hath created a strong password, fair Juliet.
  printf("Romeo: The password meeteth all requirements. Thou hath created a strong password, fair Juliet.\n");
  printf("Juliet: Thank thee, kind Romeo, for thy assistance.\n");
  printf("Romeo: 'Twas my pleasure to be of service, fair Juliet. Farewell!\n");
  
  return 0;
}