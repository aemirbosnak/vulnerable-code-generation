//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 4096

void backup_file(char *filename)
{
  FILE *fp_src, *fp_dest;
  char buffer[MAX_BUFFER_SIZE];
  int read_size, write_size;

  fp_src = fopen(filename, "r");
  if (fp_src == NULL)
  {
    printf("Error opening file: %s\n", filename);
    return;
  }

  fp_dest = fopen("backup.dat", "a");
  if (fp_dest == NULL)
  {
    fclose(fp_src);
    printf("Error opening file: backup.dat\n");
    return;
  }

  while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, fp_src)) > 0)
  {
    write_size = fwrite(buffer, 1, read_size, fp_dest);
    if (write_size != read_size)
    {
      fclose(fp_src);
      fclose(fp_dest);
      printf("Error writing file: %s\n", filename);
      return;
    }
  }

  fclose(fp_src);
  fclose(fp_dest);

  printf("File %s successfully backed up.\n", filename);
}

int main()
{
  char filename[256];

  printf("Enter file name: ");
  scanf("%s", filename);

  backup_file(filename);

  return 0;
}