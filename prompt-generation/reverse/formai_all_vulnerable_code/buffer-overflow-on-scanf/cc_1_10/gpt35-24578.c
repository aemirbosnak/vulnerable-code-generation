//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 50

int main()
{
  char message[MAX_SIZE];
  int watermark[MAX_SIZE];
  int i, j, sum = 0, hash = 0;

  printf("Enter the message to be watermarked: ");
  scanf("%s", message);

  //Generate the watermark for the message
  for(i = 0; i < strlen(message); i++)
  {
    watermark[i] = ((i + 1) * message[i]) % 256;
    sum += watermark[i];
  }

  //Add hash for extra security
  hash = sum % 256;

  //Watermark the message
  for(i = 0, j = strlen(message); i < strlen(message); i++, j++)
  {
    message[j] = (message[i] + watermark[i]) % 256;
  }

  //Add hash to message
  message[j] = hash;

  //Display the watermarked message
  printf("Watermarked message: ");

  for(i = 0; i < strlen(message)+1; i++)
  {
    printf("%d ", message[i]);
  }

  printf("\n");

  //Remove the watermark from message
  for(i = 0, j = strlen(message) - 2; i < strlen(message) - 1; i++, j--)
  {
    message[i] = (message[j] - watermark[j]) % 256;
  }

  //Verify hash
  sum = 0;

  for(i = 0; i < strlen(message) - 1; i++)
  {
    sum += watermark[i];
  }

  if(sum % 256 == message[strlen(message) - 1])
  {
    printf("Watermark verified!\n");
  }
  else
  {
    printf("Watermark tampered!\n");
  }

  return 0;
}