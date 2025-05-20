//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }

  int fd_in, fd_out;
  if ((fd_in = open(argv[1], O_RDONLY)) == -1)
  {
    perror("Error opening input file");
    exit(1);
  }
  if ((fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
  {
    perror("Error opening output file");
    exit(1);
  }

  char *buf;
  struct stat st;
  if (stat(argv[1], &st) == -1)
  {
    perror("Error getting file size");
    exit(1);
  }
  buf = malloc(st.st_size + 1);
  if (buf == NULL)
  {
    perror("Error allocating memory");
    exit(1);
  }

  if (read(fd_in, buf, st.st_size) != st.st_size)
  {
    perror("Error reading from input file");
    exit(1);
  }

  int i, j;
  for (i = 0; i < st.st_size; i++)
  {
    if ((buf[i] == '\r') && (buf[i + 1] == '\n'))
    {
      buf[i] = '/';
      buf[i + 1] = '0';
      i += 1;
      while ((buf[i] != '\n') && (i < st.st_size))
      {
        buf[i] = '0';
        i++;
      }
    }
    else if (buf[i] == '\n')
    {
      buf[i] = '/';
      while ((buf[i] != '\n') && (i < st.st_size))
      {
        buf[i] = '0';
        i++;
      }
    }
  }

  if (write(fd_out, buf, st.st_size) != st.st_size)
  {
    perror("Error writing to output file");
    exit(1);
  }

  free(buf);
  close(fd_in);
  close(fd_out);

  return 0;
}