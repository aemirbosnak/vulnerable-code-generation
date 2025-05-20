#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int line_num = 0;
  char buffer[10000];

  printf("Enter command (add, del, edit, save, exit): ");
  char cmd[20];
  scanf("%s", cmd);

  switch (cmd[0]) {
    case 'a':
      printf("Enter text: ");
      scanf("%s", buffer);
      line_num++;
      break;
    case 'd':
      printf("Enter line number: ");
      int line_num_del;
      scanf("%d", &line_num_del);
      line_num--;
      break;
    case 'e':
      printf("Enter line number: ");
      int line_num_edit;
      scanf("%d", &line_num_edit);
      printf("Enter new text: ");
      scanf("%s", buffer);
      break;
    case 's':
      FILE *fp = fopen("text.txt", "w");
      fprintf(fp, "%s", buffer);
      fclose(fp);
      break;
    case 'x':
      exit(0);
  }

  printf("Line number: %d\n", line_num);
  printf("Text: %s", buffer);

  return 0;
}
