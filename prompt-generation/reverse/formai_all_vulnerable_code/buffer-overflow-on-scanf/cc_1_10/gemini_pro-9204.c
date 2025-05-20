//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

typedef struct {
  int length;
  int lowercase;
  int uppercase;
  int digits;
  int symbols;
} PasswordScore;

int calculate_score(char *password) {
  PasswordScore score = {0, 0, 0, 0, 0};

  score.length = strlen(password);

  for (int i = 0; i < score.length; i++) {
    char c = password[i];

    if (c >= 'a' && c <= 'z') {
      score.lowercase++;
    } else if (c >= 'A' && c <= 'Z') {
      score.uppercase++;
    } else if (c >= '0' && c <= '9') {
      score.digits++;
    } else {
      score.symbols++;
    }
  }

  return score.length * (score.lowercase + score.uppercase + score.digits + score.symbols);
}

int main() {
  char password[100];

  printf("My dearest love,\n\n");
  printf("I pen this code to you tonight, not out of duty, but borne on the wings of my heart's affection.\n");
  printf("As you know, in this realm of cyberspace, our secrets must be guarded with utmost care.\n");
  printf("That is why I beseech you to choose a password that would be as unyielding as our love.\n\n");

  printf("Enter your desired password, my cherished one: ");
  scanf("%s", password);

  int score = calculate_score(password);

  if (score < MIN_LENGTH) {
    printf("My love, I must confess that your password is too short.\n");
    printf("It must contain at least %d characters.\n", MIN_LENGTH);
  } else if (score < 20) {
    printf("My dearest, your password could be stronger.\n");
    printf("It should contain a mix of lowercase, uppercase, digits, and symbols.\n");
  } else {
    printf("My heart leaps with joy, my love!\n");
    printf("Your password is as strong and unwavering as our bond.\n");
  }

  printf("\nWith your password safeguarded, we can embark on our digital adventures together.\n");
  printf("Know that my love for you will forever burn brighter than a thousand suns.\n\n");

  printf("Yours eternally,\n\n");
  printf("Your loving suitor\n");

  return 0;
}