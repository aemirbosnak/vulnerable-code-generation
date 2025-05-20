#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("database.txt", "w");
  fprintf(fp, "CREATE DATABASE IF NOT EXISTS my_database;");
  fclose(fp);

  system("mysqldump -u root -p my_database > database.sql");
  system("rm -f database.txt");

  return 0;
}
