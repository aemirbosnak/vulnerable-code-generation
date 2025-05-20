//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>

void htmlBeautifier() {
  int i, n;
  printf("Enter the number of lines: ");
  scanf("%d", &n);
  
  for (i = 0; i < n; i++) {
    char str[100], *p, *q, *s;
    printf("Enter the line: ");
    gets(str);
    
    p = strtok(str, " ");
    while (p) {
      q = p;
      while (*q && *q!= '\n' && *q!= '\r') {
        q++;
      }
      *q = '\0';
      
      s = strchr(q, '<');
      if (s) {
        int j, k = 0;
        for (j = s - q; j < strlen(q); j++) {
          if (q[j] == '<') {
            k++;
          } else if (q[j] == '>') {
            k--;
          } else if (q[j] == '&') {
            k = 0;
          }
          if (k == 0) {
            break;
          }
        }
        if (k == 0) {
          printf("</%s>", q);
        } else {
          printf("%s", q);
        }
      } else {
        printf("%s", q);
      }
      p = strtok(NULL, " ");
    }
    printf("\n");
  }
}

int main() {
  htmlBeautifier();
  return 0;
}