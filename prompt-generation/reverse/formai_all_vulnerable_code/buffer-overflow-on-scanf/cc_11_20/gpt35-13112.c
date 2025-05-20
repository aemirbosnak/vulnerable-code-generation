//FormAI DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char fileName[100];
  printf("Enter the name of the log file: ");
  scanf("%s", fileName);

  FILE *fp = fopen(fileName, "r");
  if (fp == NULL)
  {
    printf("Error opening file. Program terminating.\n");
    exit(0);
  }

  char line[256];
  int totalRequests = 0, successfulRequests = 0, clientErrors = 0, serverErrors = 0;

  while (fgets(line, sizeof(line), fp))
  {
    totalRequests++;

    char *token = strtok(line, " ");

    // Check the status code
    while (token != NULL)
    {
      if (strcmp(token, "200") == 0)
      {
        successfulRequests++;
        break;
      }
      else if (strcmp(token, "400") == 0 || strcmp(token, "401") == 0 || strcmp(token, "403") == 0 || strcmp(token, "404") == 0)
      {
        clientErrors++;
        break;
      }
      else if (strcmp(token, "500") == 0 || strcmp(token, "502") == 0 || strcmp(token, "503") == 0 || strcmp(token, "504") == 0)
      {
        serverErrors++;
        break;
      }

      token = strtok(NULL, " ");
    }
  }

  printf("Total requests: %d\n", totalRequests);
  printf("Successful requests: %d\n", successfulRequests);
  printf("Client errors: %d\n", clientErrors);
  printf("Server errors: %d\n", serverErrors);

  fclose(fp);

  return 0;
}