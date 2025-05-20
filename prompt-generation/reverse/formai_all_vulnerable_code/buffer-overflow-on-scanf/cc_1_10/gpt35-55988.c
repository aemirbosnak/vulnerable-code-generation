//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
The following program is a paranoid style Ebook reader that will only allow
authorized users to access the content. The user must enter a valid password
to gain access to the Ebook. The program will also check if the Ebook file
exists and is not corrupted before allowing the user to read it. 
*/

int main() {
  
  char password[20]; // User password
  char content[1000]; // Ebook content
  FILE *fp; // Ebook file pointer
    
  // Get user password input
  printf("Enter password to access Ebook: ");
  scanf("%s", password);
  
  // Verify password
  if (strcmp(password, "password123") != 0) {
    printf("Unauthorized access attempted. Terminating program...\n");
    exit(1);
  }
  
  // Check if Ebook file exists
  if ((fp = fopen("Ebook.txt", "r")) == NULL) {
    printf("Ebook not found. Terminating program...\n");
    exit(1);
  }
  
  // Verify Ebook file integrity
  int contentLen = 0; // Ebook content length
  char c; // Current character in file
  bool isCorrupted = false; // Flag for corrupted file
  
  while ((c = fgetc(fp)) != EOF) { 
    content[contentLen++] = c;
    if (contentLen >= 1000) {
      isCorrupted = true;
      break;
    }
  }
  
  if (isCorrupted) {
    printf("Ebook file corrupted. Terminating program...\n");
    exit(1);
  }
  
  // Close Ebook file
  fclose(fp);
  
  // Display Ebook content
  printf("\nEbook content:\n%s\n\n", content);
  
  return 0;
}