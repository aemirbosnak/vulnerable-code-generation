//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  srand(time(0));
  int choice;
  char name[20];
  printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
  scanf("%s", name);
  printf("\nHello, %s! I'm here to tell you your fortune. Please choose a category:\n", name);
  printf("1. Love\n2. Career\n3. Health\n4. Wealth\n5. Luck\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("\nLove:\n");
      printf("You will meet someone special soon.\n");
      printf("This person will bring great joy and happiness into your life.\n");
      printf("You will experience a deep connection with them.\n");
      printf("Your love life will flourish.\n");
      break;
    case 2:
      printf("\nCareer:\n");
      printf("You will have great success in your career.\n");
      printf("Your hard work and dedication will pay off.\n");
      printf("You will be recognized for your talents and skills.\n");
      printf("A new opportunity will present itself to you.\n");
      break;
    case 3:
      printf("\nHealth:\n");
      printf("You will enjoy good health.\n");
      printf("Your energy levels will be high.\n");
      printf("You will feel strong and vibrant.\n");
      printf("You will have a positive outlook on life.\n");
      break;
    case 4:
      printf("\nWealth:\n");
      printf("You will experience financial abundance.\n");
      printf("Money will come to you easily and effortlessly.\n");
      printf("You will have more than enough to meet your needs.\n");
      printf("You will be able to enjoy the finer things in life.\n");
      break;
    case 5:
      printf("\nLuck:\n");
      printf("You will have good luck in all areas of your life.\n");
      printf("Opportunities will come your way.\n");
      printf("You will be in the right place at the right time.\n");
      printf("Your dreams will come true.\n");
      break;
    default:
      printf("\nInvalid choice. Please try again.\n");
  }
  return 0;
}