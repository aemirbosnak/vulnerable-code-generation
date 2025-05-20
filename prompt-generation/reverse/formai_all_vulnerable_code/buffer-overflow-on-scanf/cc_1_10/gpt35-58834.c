//FormAI DATASET v1.0 Category: Database querying ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

void finish_with_error(MYSQL *con) {
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main() {
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) {
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }

  if (mysql_real_connect(con, "localhost", "user", "password", 
          "database", 0, NULL, 0) == NULL) {
    finish_with_error(con);
  }  

  char query[200];
  printf("Enter the name of the student to search: ");
  scanf("%s", query);
  
  char *search_name = query;
  char *search_query = malloc(strlen(search_name)+76);
  if (search_query == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(1);
  }
  strcpy(search_query, "SELECT * FROM students WHERE name = '");
  strcat(search_query, search_name);
  strcat(search_query, "'");

  if (mysql_query(con, search_query)) {
    finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL) {
    finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) { 
      printf("The details of the student %s are:\n\n", search_name);
      for(int i = 0; i < num_fields; i++) { 
          printf("%s ", row[i] ? row[i] : "NULL"); 
      } 
      printf("\n\n"); 
  }

  mysql_free_result(result);
  mysql_close(con);
  return 0;
}