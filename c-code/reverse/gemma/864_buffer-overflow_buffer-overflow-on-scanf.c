#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char filename[256];
  printf("Enter file name: ");
  scanf("%s", filename);

  // Buffer overflow vulnerability
  char data[1024];
  printf("Enter data: ");
  scanf("%s", data);

  FILE *fp = fopen(filename, "w");
  if (fp) {
    fwrite(data, 1, strlen(data) + 1, fp);
    fclose(fp);
  } else {
    printf("Error opening file.\n");
  }

  return 0;
}
